#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cows(n, vector<int>(m));
    vector<int> p(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cows[i][j];
        }
        // Sort cards to easily check the arithmetic progression
        sort(cows[i].begin(), cows[i].end());
    }

    for (int i = 0; i < n; i++) {
        // The smallest card must be < n for the cow to play in the first round.
        // This smallest card 'r' determines the cow's turn index (0-based).
        if (cows[i][0] >= n) {
            cout << "-1\n";
            return;
        }

        int turn_index = cows[i][0];

        // Check if the rest of the cards follow the required pattern: val, val+n, val+2n...
        for (int j = 1; j < m; j++) {
            if (cows[i][j] != cows[i][0] + j * n) {
                cout << "-1\n";
                return;
            }
        }

        // Check if multiple cows try to claim the same turn index
        if (p[turn_index] != 0) {
            cout << "-1\n";
            return;
        }

        // Store result (1-based index)
        p[turn_index] = i + 1;
    }

    // Print the permutation
    for (int i = 0; i < n; i++) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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