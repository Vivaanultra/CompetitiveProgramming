#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> sequences(n, vector<int>(n - 1));
    map<int, int> first_elem_counts;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> sequences[i][j];
        }
        first_elem_counts[sequences[i][0]]++;
    }

    int p1 = 0;
    for (auto const& [val, count] : first_elem_counts) {
        if (count == n - 1) {
            p1 = val;
            break;
        }
    }

    cout << p1 << " ";

    for (int i = 0; i < n; ++i) {
        if (sequences[i][0] != p1) {
            for (int j = 0; j < n - 1; ++j) {
                cout << sequences[i][j] << " ";
            }
            break;
        }
    }
    cout << endl;
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