#include <bits/stdc++.h>

using namespace std;

bool check(long long T, int n, int k, long long x, const vector<long long>& a) {
    if (T == 0) return true;

    vector<pair<long long, long long>> intervals;
    for (int i = 0; i < n; i++) {
        long long l = max(0LL, a[i] - T + 1);
        long long r = min(x, a[i] + T - 1);
        if (l <= r) {
            intervals.push_back({l, r});
        }
    }

    if (intervals.empty()) {
        return (x + 1) >= k;
    }

    vector<pair<long long, long long>> merged;
    long long current_l = intervals[0].first;
    long long current_r = intervals[0].second;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first > current_r + 1) {
            merged.push_back({current_l, current_r});
            current_l = intervals[i].first;
            current_r = intervals[i].second;
        } else {
            current_r = max(current_r, intervals[i].second);
        }
    }
    merged.push_back({current_l, current_r});

    long long forbidden_count = 0;
    for (auto p : merged) {
        forbidden_count += (p.second - p.first + 1);
    }

    long long allowed_count = (x + 1) - forbidden_count;
    return allowed_count >= k;
}

void solve() {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long low = 0, high = x + 1, ans_T = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, k, x, a)) {
            ans_T = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    vector<pair<long long, long long>> intervals;
    for (int i = 0; i < n; i++) {
        long long l = max(0LL, a[i] - ans_T + 1);
        long long r = min(x, a[i] + ans_T - 1);
        if (l <= r) {
            intervals.push_back({l, r});
        }
    }
    
    vector<pair<long long, long long>> merged;
    if (!intervals.empty()) {
        long long current_l = intervals[0].first;
        long long current_r = intervals[0].second;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > current_r + 1) {
                merged.push_back({current_l, current_r});
                current_l = intervals[i].first;
                current_r = intervals[i].second;
            } else {
                current_r = max(current_r, intervals[i].second);
            }
        }
        merged.push_back({current_l, current_r});
    }

    int count = 0;
    long long current_pos = 0;
    for (auto p : merged) {
        long long l = p.first;
        long long r = p.second;
        while (current_pos < l && count < k) {
            cout << current_pos << " ";
            count++;
            current_pos++;
        }
        current_pos = r + 1;
    }

    while (current_pos <= x && count < k) {
        cout << current_pos << " ";
        count++;
        current_pos++;
    }
    cout << "\n";
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