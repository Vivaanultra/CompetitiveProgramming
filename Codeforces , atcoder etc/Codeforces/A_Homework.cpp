#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int m;
    cin >> m;
    string b, c;
    cin >> b >> c;

    deque<char> result_dq;
    for (char ch : a) {
        result_dq.push_back(ch);
    }

    for (int i = 0; i < m; ++i) {
        if (c[i] == 'V') {
            result_dq.push_front(b[i]);
        } else {
            result_dq.push_back(b[i]);
        }
    }

    for (char ch : result_dq) {
        cout << ch;
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