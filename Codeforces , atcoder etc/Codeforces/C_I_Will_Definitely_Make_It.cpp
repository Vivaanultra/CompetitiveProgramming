#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    --k;

    vector<long long> h(n);
    long long h_start = 0;
    long long h_max = 0;
    set<long long> unique_heights;

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (i == k) {
            h_start = h[i];
        }
        h_max = max(h_max, h[i]);
        unique_heights.insert(h[i]);
    }

    if (h_start >= h_max) {
        cout << "YES" << endl;
        return;
    }

    vector<long long> path_heights;
    for (long long height : unique_heights) {
        if (height >= h_start) {
            path_heights.push_back(height);
        }
    }
    
    // In set, heights are already sorted. No need to sort path_heights again.

    long long current_h = h_start;
    for (size_t i = 1; i < path_heights.size(); ++i) {
        if (path_heights[i] - current_h > h_start) {
             cout << "NO" << endl;
             return;
        }
        current_h = path_heights[i];
    }
    
    cout << "YES" << endl;
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