#include <bits/stdc++.h>

using namespace std;

vector<int> p;
string s;

bool solve(int l, int r) {
    if (l > r) {
        return true;
    }

    int x = -1;
    for (int i = l; i <= r; ++i) {
        if (s[i - 1] == '1') {
            x = i;
            break;
        }
    }

    if (x == -1) {
        if (l == r) {
            return false;
        }
        for (int i = l; i < r; ++i) {
            p[i - 1] = i + 1;
        }
        p[r - 1] = l;
        return true;
    } else {
        p[x - 1] = x;
        bool left_ok = solve(l, x - 1);
        bool right_ok = solve(x + 1, r);
        return left_ok && right_ok;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> s;
        p.assign(n, 0);

        if (solve(1, n)) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << p[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}