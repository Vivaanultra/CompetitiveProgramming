#include <bits/stdc++.h>

using namespace std;

long long solve_line(const vector<int>& costs) {
    int n = costs.size();
    if (n == 0) {
        return 0;
    }

    vector<vector<long long>> dp(n, vector<long long>(2));

    dp[0][1] = costs[0];
    dp[0][0] = 0;

    for (int i = 1; i < n; ++i) {
        dp[i][1] = costs[i] + min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = dp[i - 1][1];
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    if (n == 1) {
        cout << costs[0] << "\n";
        return 0;
    }

    // Case 1: Assume Knight N (last knight) is FED
    vector<int> line1(costs.begin(), costs.end() - 1);
    long long cost1 = costs.back() + solve_line(line1);

    // Case 2: Assume Knight N (last knight) is SKIPPED
    // This forces Knight N-1 and Knight 1 to be fed.
    long long cost2 = 0;
    if (n > 1) {
        cost2 += costs[n-2];
    }
    if (n > 2) {
        cost2 += costs[0];
        vector<int> line2(costs.begin() + 1, costs.end() - 2);
        cost2 += solve_line(line2);
    }
    
    cout << min(cost1, cost2) << "\n";

    return 0;
}