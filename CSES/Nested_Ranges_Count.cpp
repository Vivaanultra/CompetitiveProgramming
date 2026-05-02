#include <bits/stdc++.h>
using namespace std;


const int MAXN = 200005;
int bit[MAXN];
int n;

void update(int idx, int val) {
    for (; idx < MAXN; idx += idx & -idx)
        bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

struct Range {
    int l, r, id;
    bool operator<(const Range& other) const {
        if (l == other.l)
            return r > other.r; 
        return l < other.l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    vector<Range> ranges(n);
    vector<int> y_coords;
    
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
        y_coords.push_back(ranges[i].r);
    }
  
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());

    auto get_rank = [&](int val) {
        return lower_bound(y_coords.begin(), y_coords.end(), val) - y_coords.begin() + 1;
    };

    
    sort(ranges.begin(), ranges.end());

    vector<int> contained_count(n);
    vector<int> contains_count(n);
  
    for (int i = n - 1; i >= 0; i--) {
        int y_rank = get_rank(ranges[i].r);
        contains_count[ranges[i].id] = query(y_rank);
        update(y_rank, 1);
    }
  
    fill(bit, bit + MAXN, 0);
   
    for (int i = 0; i < n; i++) {
        int y_rank = get_rank(ranges[i].r);
        int total_processed = i; 
        int smaller_ends = query(y_rank - 1);
        contained_count[ranges[i].id] = total_processed - smaller_ends;
        
        update(y_rank, 1);
    }
   
    for (int i = 0; i < n; i++) cout << contains_count[i] << (i == n-1 ? "" : " ");
    cout << "\n";
    for (int i = 0; i < n; i++) cout << contained_count[i] << (i == n-1 ? "" : " ");
    cout << "\n";

    return 0;
}