#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i];
    }

    for (int i = 0; i < n; ++i) {
        // For each person i, we need to find if they have at least one valid choice.
        bool can_use_s = true;
        bool can_use_t = true;

        // Check if s[i] is a valid nickname for person i
        for (int j = 0; j < n; ++j) {
            if (i == j) continue; // Don't check against self
            if (s[i] == s[j] || s[i] == t[j]) {
                can_use_s = false;
                break;
            }
        }

        // Check if t[i] is a valid nickname for person i
        // (Only if s[i] is not the same as t[i])
        if (s[i] != t[i]) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (t[i] == s[j] || t[i] == t[j]) {
                    can_use_t = false;
                    break;
                }
            }
        } else {
            // If s[i] and t[i] are the same, the validity of t[i] is the same as s[i]
            can_use_t = can_use_s;
        }

        // If neither name can be used, it's impossible.
        if (!can_use_s && !can_use_t) {
            cout << "No\n";
            return;
        }
    }

    // If we get through the loop, everyone had at least one option.
    cout << "Yes\n";
}

int main() {
    // The problem doesn't have multiple test cases, but this is good practice.
    // Let's adapt to the problem's single test case format.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}