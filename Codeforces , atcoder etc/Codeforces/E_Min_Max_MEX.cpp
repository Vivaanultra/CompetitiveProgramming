#include <bits/stdc++.h>
using namespace std;

bool check(int x, int k, int n, const vector<int>& a) {
    if (x == 0) return true;
    
    int subarrays_found = 0;
    vector<int> window_counts(x, 0);
    int distinct_in_window = 0;
    
    int l = 0;
    for (int r = 0; r < n; ++r) {
        int val = a[r];
        if (val < x) {
            if (window_counts[val] == 0) {
                distinct_in_window++;
            }
            window_counts[val]++;
        }

        if (distinct_in_window == x) {
            subarrays_found++;
            // Reset for the next subarray search
            l = r + 1;
            fill(window_counts.begin(), window_counts.end(), 0);
            distinct_in_window = 0;
        }
    }
    return subarrays_found >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, k, n, a)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
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