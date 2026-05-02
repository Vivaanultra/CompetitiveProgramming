#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> prefA(n + 1, vector<int>(26, 0));
    vector<vector<int>> prefB(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            prefA[i + 1][j] = prefA[i][j];
            prefB[i + 1][j] = prefB[i][j];
        }
        prefA[i + 1][a[i] - 'a']++;
        prefB[i + 1][b[i] - 'a']++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int diff = 0;
        for (int i = 0; i < 26; i++) {
            int countA = prefA[r][i] - prefA[l - 1][i];
            int countB = prefB[r][i] - prefB[l - 1][i];
            diff += abs(countA - countB);
        }
        
        cout << diff / 2 << "\n";
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