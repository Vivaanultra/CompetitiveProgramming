#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }

    // Step 1: Pre-compute the prefix OR matrix 'b'
    vector<vector<int>> b(n, vector<int>(k));
    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            b[i][j] = b[i - 1][j] | a[i][j];
        }
    }

    // Step 2 & 3: Process queries using binary search
    for (int qi = 0; qi < q; ++qi) {
        int m;
        cin >> m;
        
        int min_country = 1;
        int max_country = n;

        for (int mi = 0; mi < m; ++mi) {
            int r;
            char o;
            long long c;
            cin >> r >> o >> c;
            r--; // Adjust to 0-based index

            if (o == '>') {
                // Find the first country i where b[i][r] > c
                // This gives a lower bound
                int low = 0, high = n - 1, ans = n + 1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (b[mid][r] > c) {
                        ans = mid + 1;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                min_country = max(min_country, ans);
            } else { // o == '<'
                // Find the last country i where b[i][r] < c
                // This gives an upper bound
                int low = 0, high = n - 1, ans = 0;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (b[mid][r] < c) {
                        ans = mid + 1;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                max_country = min(max_country, ans);
            }
        }

        // Output the final result
        if (min_country <= max_country) {
            cout << min_country << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}