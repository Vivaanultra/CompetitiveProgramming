#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    for (int i = 1; i < s.length(); ++i) {
        string s_a = s.substr(0, i);
        string s_b = s.substr(i);

        if (s_b[0] == '0') {
            continue;
        }

        int a = stoi(s_a);
        int b = stoi(s_b);

        if (b > a) {
            cout << a << " " << b << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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