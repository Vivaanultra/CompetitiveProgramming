#include <bits/stdc++.h>

using namespace std;

// Solves for the max number of non-adjacent elements <= max_val in a range
int solve_dp(const vector<int>& arr, int max_val) {
    if (arr.empty()) {
        return 0;
    }
    int n = arr.size();
    vector<int> dp(n, 0);

    if (arr[0] <= max_val) {
        dp[0] = 1;
    }

    for (int i = 1; i < n; ++i) {
        int take = 0;
        if (arr[i] <= max_val) {
            take = 1 + (i > 1 ? dp[i - 2] : 0);
        }
        int leave = dp[i - 1];
        dp[i] = max(take, leave);
    }
    return dp[n - 1];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_score = 0;

    for (int i = 0; i < n; ++i) {
        long long current_max_val = a[i];
        
        vector<int> left_arr, right_arr;
        if (i - 2 >= 0) {
            left_arr.assign(a.begin(), a.begin() + i - 1);
        }
        if (i + 2 < n) {
            right_arr.assign(a.begin() + i + 2, a.end());
        }
        
        long long count_left = solve_dp(left_arr, current_max_val);
        long long count_right = solve_dp(right_arr, current_max_val);

        long long current_score = current_max_val + 1 + count_left + count_right;
        max_score = max(max_score, current_score);
    }
    cout << max_score << "\n";
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