#include <bits/stdc++.h>

using namespace std;

void solve() {
    int q;
    cin >> q;

    long long len_s = 1;
    long long len_t = 1;
    bool s_has_gt_a = false;
    bool t_has_gt_a = false;

    while (q--) {
        int d;
        long long k;
        string x;
        cin >> d >> k >> x;

        if (d == 1) {
            len_s += k * x.length();
            // If s already has a non-'a' character, it will always have one.
            // Otherwise, check if the new string x adds one.
            if (!s_has_gt_a) {
                for (char c : x) {
                    if (c > 'a') {
                        s_has_gt_a = true;
                        break;
                    }
                }
            }
        } else { // d == 2
            len_t += k * x.length();
            if (!t_has_gt_a) {
                for (char c : x) {
                    if (c > 'a') {
                        t_has_gt_a = true;
                        break;
                    }
                }
            }
        }

        // The logic we derived:
        // 1. If t has a character > 'a', we can always make s < t.
        if (t_has_gt_a) {
            cout << "YES\n";
        }
        // 2. If t only has 'a's, but s has something > 'a', s can't be made smaller.
        else if (s_has_gt_a) {
            cout << "NO\n";
        }
        // 3. If both only have 'a's, s must be shorter than t.
        else if (len_s < len_t) {
            cout << "YES\n";
        }
        // 4. Otherwise, it's impossible.
        else {
            cout << "NO\n";
        }
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