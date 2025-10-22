#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> pz(n + 1, 0);
    vector<int> po(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pz[i + 1] = pz[i] + (s[i] == '0');
        po[i + 1] = po[i] + (s[i] == '1');
    }

    int total_ones = po[n];
    int ans = n;
    int low = 0, high = n;

    while (low <= high) {
        int k = low + (high - low) / 2;
        bool possible = false;

        if (total_ones <= k) {
            possible = true;
        } else {
            for (int j = 1; j <= n; ++j) {
                int target_pz = pz[j] - k;
                
                auto it = lower_bound(pz.begin(), pz.begin() + j + 1, target_pz);
                int l = distance(pz.begin(), it);

                if (po[l] <= po[j] + k - total_ones) {
                    possible = true;
                    break;
                }
            }
        }

        if (possible) {
            ans = k;
            high = k - 1;
        } else {
            low = k + 1;
        }
    }
    cout << ans << "\n";
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