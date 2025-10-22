#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    int doubles = 0;
    int singles = 0;
    
    for (int i = 0; i < 26; i++) {
        if (freq[i] >= 2) {
            doubles++;
        } else if (freq[i] == 1) {
            singles++;
        }
    }
    
    int k = doubles + (singles / 2);
    cout << k << endl;
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