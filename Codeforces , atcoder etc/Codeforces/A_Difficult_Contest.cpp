#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int countF = 0;
    int countN = 0;
    int countT = 0;
    string other_chars;

    for (char c : s) {
        if (c == 'F') {
            countF++;
        } else if (c == 'N') {
            countN++;
        } else if (c == 'T') {
            countT++;
        } else {
            other_chars += c;
        }
    }

    // Print all 'T's first
    for (int i = 0; i < countT; ++i) {
        cout << 'T';
    }

    // Print all 'F's
    for (int i = 0; i < countF; ++i) {
        cout << 'F';
    }

    // Print all 'N's
    for (int i = 0; i < countN; ++i) {
        cout << 'N';
    }

    // Print the rest of the characters
    sort(other_chars.begin(), other_chars.end());
    cout << other_chars << "\n";
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