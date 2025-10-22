#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> matrix(n, vector<int>(n));
    int current_num = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (current_num > n * n) {
                break;
            }
            matrix[i][j] = current_num;
            current_num += 2;
        }
    }

    current_num = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                if (current_num > n * n) {
                    break;
                }
                matrix[i][j] = current_num;
                current_num += 2;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
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