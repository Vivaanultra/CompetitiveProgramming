#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    if (n % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    string s1 = s.substr(0, 3 * n / 2);
    string s2 = s.substr(3 * n / 2);

    if (s1 == s2) {
        cout << 1 << "\n";
        for (int i = 0; i < 3 * n; ++i) {
            cout << 1 << (i == 3 * n - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    cout << 2 << "\n";
    vector<int> a(3 * n);
    int h = n / 2;

    for (int i = 0; i < h; ++i) {
        int p1 = 3 * i;
        int p2 = 3 * (h + i);
        string b1 = s.substr(p1, 3);
        string b2 = s.substr(p2, 3);

        if (b1 == b2) {
            for (int j = 0; j < 3; ++j) {
                a[p1 + j] = 1;
                a[p2 + j] = 1;
            }
        } else {
            bool f = false;
            for (int x = 0; x < 3 && !f; ++x) {
                for (int y = 0; y < 3 && !f; ++y) {
                    if (b1[x] == b2[y]) {
                        string l1 = "", l2 = "";
                        for (int j = 0; j < 3; ++j) if (j != x) l1 += b1[j];
                        for (int j = 0; j < 3; ++j) if (j != y) l2 += b2[j];
                        
                        if (l1 == l2) {
                            a[p1 + x] = 2;
                            a[p2 + y] = 2;
                            for (int j = 0; j < 3; ++j) if (j != x) a[p1 + j] = 1;
                            for (int j = 0; j < 3; ++j) if (j != y) a[p2 + j] = 1;
                            f = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3 * n; ++i) {
        cout << a[i] << (i == 3 * n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k;
    if (cin >> t >> k) {
        while (t--) {
            solve();
        }
    }
    return 0;
}