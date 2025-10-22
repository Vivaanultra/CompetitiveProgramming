#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_count = 0;
    int r1 = 0, r2 = 0;
    map<int, int> freq;

    for (int left = 0; left < n; ++left) {
        // Expand r1 to find the start of the k-distinct segment.
        // The map `freq` will represent the window [left, r1-1].
        while (r1 < n && freq.size() < k) {
            freq[a[r1]]++;
            r1++;
        }
        
        // If we couldn't form a window with k distinct elements, we're done.
        if (freq.size() < k) {
            break;
        }

        // Expand r2 to find the end of the k-distinct segment.
        // r2 scans ahead without modifying the map.
        if (r2 < r1) {
            r2 = r1;
        }
        while (r2 < n && freq.count(a[r2])) {
            r2++;
        }

        // For this `left`, valid endpoints 'c' are in [r1-1, r2-1].
        // Intersect with length constraints [left+l-1, left+r-1].
        long long start_c = left + l - 1;
        long long end_c = left + r - 1;
        
        long long valid_start = max((long long)r1 - 1, start_c);
        long long valid_end = min((long long)r2 - 1, end_c);

        if (valid_start <= valid_end) {
            total_count += (valid_end - valid_start + 1);
        }

        // Shrink window from the left for the next iteration.
        freq[a[left]]--;
        if (freq[a[left]] == 0) {
            freq.erase(a[left]);
        }
    }

    cout << total_count << "\n";
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