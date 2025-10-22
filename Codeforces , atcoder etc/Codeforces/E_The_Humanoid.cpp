#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<vector<int>> strategies = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};
    int max_absorbed = 0;

    for (const auto& strategy : strategies) {
        long long current_h = h;
        int absorbed_count = 0;
        int astro_idx = 0;
        int serum_idx = 0;

        while (astro_idx < n) {
            if (current_h > a[astro_idx]) {
                current_h += a[astro_idx] / 2;
                absorbed_count++;
                astro_idx++;
            } else if (serum_idx < 3) {
                current_h *= strategy[serum_idx];
                serum_idx++;
            } else {
                break;
            }
        }
        max_absorbed = max(max_absorbed, absorbed_count);
    }

    cout << max_absorbed << endl;
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