#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Find the alphabetically largest character in the string.
    char max_char = 'a';
    for (char c : s) {
        if (c > max_char) {
            max_char = c;
        }
    }

    // The alphabet size is the 1-based position of that character.
    // 'a' is the 1st letter, 'b' is the 2nd, and so on.
    // (max_char - 'a') gives the 0-based index, so we add 1.
    cout << (max_char - 'a' + 1) << endl;
}

int main() {
    // It is currently Friday, 4:55 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}