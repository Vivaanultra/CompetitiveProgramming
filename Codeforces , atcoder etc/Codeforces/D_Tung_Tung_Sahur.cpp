#include <bits/stdc++.h>
using namespace std;

void solve() {
    string p, s;
    cin >> p >> s;

    int p_idx = 0;
    int s_idx = 0;

    while (p_idx < p.length()) {
        // If we have hits left in 'p' but no sounds left in 's', it's impossible.
        if (s_idx >= s.length()) {
            cout << "NO\n";
            return;
        }

        // The characters of the current groups must match.
        if (p[p_idx] != s[s_idx]) {
            cout << "NO\n";
            return;
        }

        // Find the length of the current group of identical characters in 'p'.
        int p_runner = p_idx;
        while (p_runner < p.length() && p[p_runner] == p[p_idx]) {
            p_runner++;
        }
        int count_p = p_runner - p_idx;

        // Find the length of the corresponding group in 's'.
        int s_runner = s_idx;
        while (s_runner < s.length() && s[s_runner] == s[s_idx]) {
            s_runner++;
        }
        int count_s = s_runner - s_idx;

        // Check if the sound group's length is valid.
        // It must be at least count_p (all single hits) and at most 2*count_p (all double hits).
        if (count_s < count_p || count_s > 2 * count_p) {
            cout << "NO\n";
            return;
        }

        // Move the main pointers to the start of the next group.
        p_idx = p_runner;
        s_idx = s_runner;
    }

    // After processing all of 'p', we must also have processed all of 's'.
    // If there are leftover sounds in 's', it's not a match.
    if (s_idx == s.length()) {
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