#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; ++i) cin >> a1[i];
    for (int i = 0; i < n; ++i) cin >> a2[i];

    // Precompute prefix min/max for the first row
    vector<int> pmin(n), pmax(n);
    pmin[0] = a1[0];
    pmax[0] = a1[0];
    for (int i = 1; i < n; ++i) {
        pmin[i] = min(pmin[i - 1], a1[i]);
        pmax[i] = max(pmax[i - 1], a1[i]);
    }

    // Precompute suffix min/max for the second row
    vector<int> smin(n), smax(n);
    smin[n - 1] = a2[n - 1];
    smax[n - 1] = a2[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        smin[i] = min(smin[i + 1], a2[i]);
        smax[i] = max(smax[i + 1], a2[i]);
    }

    // min_r_at_l[x] will store min(R_k) for all paths k where L_k == x.
    // Size is 2*n + 2 because values go up to 2*n.
    int max_val = 2 * n;
    vector<int> min_r_at_l(max_val + 2, INF);

    for (int k = 0; k < n; ++k) {
        // For a path turning down at column k:
        // Path consists of prefix of row 1 ending at k, and suffix of row 2 starting at k
        int path_min = min(pmin[k], smin[k]);
        int path_max = max(pmax[k], smax[k]);

        // Record the constraint
        min_r_at_l[path_min] = min(min_r_at_l[path_min], path_max);
    }

    // Compute suffix minimums.
    // For a chosen l, we need a path such that L_k >= l.
    // The best such path is the one with the smallest R_k.
    // So for index l, we want min(R_k) over all indices >= l in the array.
    for (int l = max_val; l >= 1; --l) {
        min_r_at_l[l] = min(min_r_at_l[l], min_r_at_l[l + 1]);
    }

    long long ans = 0;
    for (int l = 1; l <= max_val; ++l) {
        int r_min = min_r_at_l[l];
        // If a valid path exists (r_min isn't INF)
        if (r_min <= max_val) {
            // All r from r_min to max_val are valid
            ans += (long long)(max_val - r_min + 1);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}