#include <bits/stdc++.h>

using namespace std;

// Data structure for the segment tree nodes
struct Node {
    int cover = 0;      // How many active rectangles cover this segment
    long long len = 0;  // The length of the covered portion of this segment
};

// Data structure for sweep-line events
struct Event {
    long long y;      // The y-coordinate of the event
    long long x1, x2; // The x-range of the interval
    int type;         // +1 for start of a rectangle, -1 for end

    bool operator<(const Event& other) const {
        return y < other.y;
    }
};

vector<Node> seg_tree;
vector<long long> x_map;

// Segment tree update function
void push_up(int u, int l, int r) {
    if (seg_tree[u].cover > 0) {
        seg_tree[u].len = x_map[r + 1] - x_map[l];
    } else if (l == r) {
        seg_tree[u].len = 0;
    } else {
        seg_tree[u].len = seg_tree[u * 2].len + seg_tree[u * 2 + 1].len;
    }
}

// Update the segment tree for a given x-range
void update(int u, int l, int r, int ql, int qr, int type) {
    if (ql > qr || l > qr || r < ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        seg_tree[u].cover += type;
    } else {
        int mid = l + (r - l) / 2;
        update(u * 2, l, mid, ql, qr, type);
        update(u * 2 + 1, mid + 1, r, ql, qr, type);
    }
    push_up(u, l, r);
}

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> x(n), r(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> r[i];

    long long total_points = 0;

    // --- Part 1: Count points on the x-axis (y=0) ---
    vector<pair<long long, long long>> intervals_y0;
    for (int i = 0; i < n; ++i) {
        intervals_y0.push_back({x[i] - r[i], x[i] + r[i]});
    }
    sort(intervals_y0.begin(), intervals_y0.end());

    long long current_start = intervals_y0[0].first;
    long long current_end = intervals_y0[0].second;
    for (int i = 1; i < n; ++i) {
        if (intervals_y0[i].first <= current_end) {
            current_end = max(current_end, intervals_y0[i].second);
        } else {
            total_points += (current_end - current_start + 1);
            current_start = intervals_y0[i].first;
            current_end = intervals_y0[i].second;
        }
    }
    total_points += (current_end - current_start + 1);

    // --- Part 2: Count points for y > 0 using sweep-line ---
    vector<Event> events;
    x_map.clear();

    for (int i = 0; i < n; ++i) {
        // For each circle, generate the rectangular strips
        for (long long d = 0; d < r[i]; ++d) {
            long long y_end = floor(sqrt(r[i] * r[i] - d * d));
            long long y_start = floor(sqrt(r[i] * r[i] - (d + 1) * (d + 1))) + 1;
            
            long long x_start = x[i] - d;
            long long x_end = x[i] + d;

            if (y_start <= y_end) {
                events.push_back({y_start, x_start, x_end, 1});
                events.push_back({y_end + 1, x_start, x_end, -1});
                x_map.push_back(x_start);
                x_map.push_back(x_end + 1);
            }
        }
    }
    
    if (events.empty()) {
        cout << total_points << "\n";
        return;
    }

    sort(x_map.begin(), x_map.end());
    x_map.erase(unique(x_map.begin(), x_map.end()), x_map.end());
    
    sort(events.begin(), events.end());
    
    int map_size = x_map.size();
    seg_tree.assign(map_size * 4, Node());

    long long total_y_gt_0 = 0;
    long long last_y = 1;

    // Process events
    for (const auto& event : events) {
        long long current_y = event.y;
        if (current_y > last_y) {
            total_y_gt_0 += seg_tree[1].len * (current_y - last_y);
        }

        int ql = lower_bound(x_map.begin(), x_map.end(), event.x1) - x_map.begin();
        int qr = lower_bound(x_map.begin(), x_map.end(), event.x2 + 1) - x_map.begin() - 1;
        
        update(1, 0, map_size - 2, ql, qr, event.type);
        last_y = current_y;
    }

    cout << total_points + 2 * total_y_gt_0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}