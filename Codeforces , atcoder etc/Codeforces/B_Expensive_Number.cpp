#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    int n = s.length();

    int max_digits_to_keep = 0;
    
    // The baseline is keeping any single non-zero digit.
    // If there's at least one non-zero digit, we can keep at least 1.
    for (char c : s) {
        if (c != '0') {
            max_digits_to_keep = 1;
            break;
        }
    }

    int zeros_before_count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            zeros_before_count++;
        } else {
            // We've found a non-zero digit.
            // A possible subsequence is all zeros seen so far, plus this digit.
            int current_len = zeros_before_count + 1;
            if (current_len > max_digits_to_keep) {
                max_digits_to_keep = current_len;
            }
        }
    }

    cout << n - max_digits_to_keep << endl;
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