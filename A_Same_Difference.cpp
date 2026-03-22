#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // The target character is always the last one
    char target = s[n-1];
    
    int ops = 0;
    // Check all characters except the last one
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != target) {
            ops++;
        }
    }
    
    cout << ops << endl;
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