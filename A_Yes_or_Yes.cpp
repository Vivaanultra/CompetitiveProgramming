#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int countY = 0;
    for (char c : s) {
        if (c == 'Y') countY++;
    }
    
    if (countY > 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}