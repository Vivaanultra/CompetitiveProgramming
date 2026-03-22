#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int k = r - l + 1; // Length of the segment to fill

        // Option 1: Consider prefix [1...r]
        vector<int> left_opts;
        for (int i = 0; i < r; i++) {
            left_opts.push_back(a[i]);
        }
        sort(left_opts.begin(), left_opts.end());
        
        long long sum1 = 0;
        for (int i = 0; i < k; i++) {
            sum1 += left_opts[i];
        }

        // Option 2: Consider suffix [l...n]
        vector<int> right_opts;
        for (int i = l - 1; i < n; i++) {
            right_opts.push_back(a[i]);
        }
        sort(right_opts.begin(), right_opts.end());

        long long sum2 = 0;
        for (int i = 0; i < k; i++) {
            sum2 += right_opts[i];
        }

        cout << min(sum1, sum2) << endl;
    }
    return 0;
}