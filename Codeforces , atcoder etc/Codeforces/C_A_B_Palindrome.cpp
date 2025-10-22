#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.length();

    for (char c : s) {
        if (c == '0') a--;
        if (c == '1') b--;
    }

    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] != '?' && s[r] != '?') {
            if (s[l] != s[r]) {
                cout << -1 << endl;
                return;
            }
        } else if (s[l] != '?') {
            s[r] = s[l];
            if (s[l] == '0') a--;
            else b--;
        } else if (s[r] != '?') {
            s[l] = s[r];
            if (s[r] == '0') a--;
            else b--;
        }
        l++;
        r--;
    }

    l = 0, r = n - 1;
    while (l < r) {
        if (s[l] == '?' && s[r] == '?') {
            if (a >= 2) {
                s[l] = s[r] = '0';
                a -= 2;
            } else if (b >= 2) {
                s[l] = s[r] = '1';
                b -= 2;
            }
        }
        l++;
        r--;
    }
    
    if (n % 2 == 1 && s[n / 2] == '?') {
        if (a > 0) {
            s[n / 2] = '0';
            a--;
        } else if (b > 0) {
            s[n / 2] = '1';
            b--;
        }
    }

    if (a == 0 && b == 0) {
        cout << s << endl;
    } else {
        cout << -1 << endl;
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