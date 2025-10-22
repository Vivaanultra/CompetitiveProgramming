//unsolved [this problem is a##]
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    long long total_ops = 0;

    // Iterate through all 2n-1 main diagonals (d = i - j)
    for (int d = 1 - n; d < n; ++d) {
        long long prev_h = 0;
        // Iterate along the current diagonal
        for (int i = 0; i < n; ++i) {
            int j = i - d;
            if (j >= 0 && j < n) {
                // h is the number of increments needed (the "fill requirement")
                long long current_h = max(0, -a[i][j]);
                // Add the "uphill climb" to the total
                total_ops += max(0LL, current_h - prev_h);
                prev_h = current_h;
            }
        }
    }
    
    cout << total_ops << "\n";
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