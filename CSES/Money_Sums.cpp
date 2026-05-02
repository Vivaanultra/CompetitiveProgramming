#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int max_sum = 100 * 1000;
    vector<bool> dp(max_sum + 1, false);
    
    // Base case
    dp[0] = true;

    // Iterate through each coin
    for (int c : coins) {
        // Iterate BACKWARDS to avoid using the same coin twice for one sum
        for (int j = max_sum; j >= c; j--) {
            if (dp[j - c]) {
                dp[j] = true;
            }
        }
    }

    // Collect all possible sums (excluding 0)
    vector<int> result;
    for (int i = 1; i <= max_sum; i++) {
        if (dp[i]) {
            result.push_back(i);
        }
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}