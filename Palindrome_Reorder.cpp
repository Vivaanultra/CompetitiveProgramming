#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int c[26] = {};
    for (char x : s) c[x - 'A']++;

    int odd = 0;
    char odd_char = 0;
    for (int i = 0; i < 26; i++) {
        if (c[i] % 2 != 0) {
            odd++;
            odd_char = i + 'A';
        }
    }

    if (odd > 1) {
        cout << "NO SOLUTION\n";
    } else {
        string t = "";
        for (int i = 0; i < 26; i++) {
            t += string(c[i] / 2, i + 'A');
        }

        cout << t;
        if (odd) cout << odd_char;
        reverse(t.begin(), t.end());
        cout << t << "\n";
    }

    return 0;
} 