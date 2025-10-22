#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

// Helper function to check one specific ordering of people
bool check(int n, long long required_sum, const vector<long long>& pa, const vector<long long>& pb, const vector<long long>& pc,
           vector<int>& p_indices, vector<int>& ans) {
    
    // Find the shortest slice for the first person
    auto it_a = lower_bound(pa.begin(), pa.end(), required_sum);
    if (it_a == pa.end()) return false;
    int r1 = distance(pa.begin(), it_a);

    // Find the shortest slice for the second person
    long long sum_at_r1 = pa[r1];
    auto it_b = lower_bound(pb.begin() + r1 + 1, pb.end(), sum_at_r1 + required_sum);
    if (it_b == pb.end()) return false;
    int r2 = distance(pb.begin(), it_b);

    // Check if the third person's remaining slice is large enough
    if (pc[n] - pc[r2] >= required_sum) {
        ans[p_indices[0] * 2] = 1;
        ans[p_indices[0] * 2 + 1] = r1;
        ans[p_indices[1] * 2] = r1 + 1;
        ans[p_indices[1] * 2 + 1] = r2;
        ans[p_indices[2] * 2] = r2 + 1;
        ans[p_indices[2] * 2 + 1] = n;
        return true;
    }
    return false;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<long long>> p_sums(3, vector<long long>(n + 1, 0));
    long long total_sum = 0;

    for (int p = 0; p < 3; ++p) {
        for (int i = 0; i < n; ++i) {
            long long val;
            cin >> val;
            p_sums[p][i + 1] = p_sums[p][i] + val;
        }
    }
    total_sum = p_sums[0][n];
    long long required_sum = (total_sum + 2) / 3; // Ceiling division

    vector<int> p_indices = {0, 1, 2}; // 0:Alice, 1:Bob, 2:Charlie
    vector<int> ans(6);

    // Check all 3! = 6 permutations
    sort(p_indices.begin(), p_indices.end());
    do {
        if (check(n, required_sum, p_sums[p_indices[0]], p_sums[p_indices[1]], p_sums[p_indices[2]], p_indices, ans)) {
            for (int i = 0; i < 6; ++i) {
                cout << ans[i] << (i == 5 ? "" : " ");
            }
            cout << "\n";
            return;
        }
    } while (next_permutation(p_indices.begin(), p_indices.end()));

    cout << -1 << "\n";
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