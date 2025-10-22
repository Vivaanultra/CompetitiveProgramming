#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Check if the string is long enough to end with "tea"
    if (n < 3) {
        cout << "No" << endl;
        return;
    }

    // Check if the last three characters match "tea"
    if (s[n - 3] == 't' && s[n - 2] == 'e' && s[n - 1] == 'a') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}