#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                // Use set {A, B}
                if (row[j] == 'A') cout << 'B';
                else cout << 'A';
            } else {
                // Use set {C, D}
                if (row[j] == 'C') cout << 'D';
                else cout << 'C';
            }
        }
        cout << "\n";
    }

    return 0;
}