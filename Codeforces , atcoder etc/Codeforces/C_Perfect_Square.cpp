#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> matrix(n);
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i];
    }

    long long total_operations = 0;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            char c1 = matrix[i][j];
            char c2 = matrix[n - 1 - j][i];
            char c3 = matrix[n - 1 - i][n - 1 - j];
            char c4 = matrix[j][n - 1 - i];

            char max_char = max({c1, c2, c3, c4});

            total_operations += (max_char - c1);
            total_operations += (max_char - c2);
            total_operations += (max_char - c3);
            total_operations += (max_char - c4);
        }
    }
    cout << total_operations << "\n";
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