#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;

    // A map from a number (1-50) to a character.
    // '\0' (null character) means we haven't seen this number yet.
    vector<char> mapping(51, '\0');
    bool possible = true;

    for (int i = 0; i < n; ++i) {
        int num = a[i];
        char letter = s[i];

        if (mapping[num] == '\0') {
            // First time seeing this number, establish the mapping.
            mapping[num] = letter;
        } else {
            // We've seen this number before, check if the letter is consistent.
            if (mapping[num] != letter) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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