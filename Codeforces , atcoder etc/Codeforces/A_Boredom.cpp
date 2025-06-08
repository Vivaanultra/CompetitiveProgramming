#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_ELEMENT_VAL = 100000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> counts(MAX_ELEMENT_VAL + 1, 0);

    for (int k = 0; k < n; ++k) {
        int val;
        cin >> val;
        if (val <= MAX_ELEMENT_VAL) {
            counts[val]++;
        }
    }

    vector<long long> dp(MAX_ELEMENT_VAL + 1, 0);

    if (MAX_ELEMENT_VAL >= 1) {
        dp[1] = (long long)1 * counts[1];
    }

    for (int i = 2; i <= MAX_ELEMENT_VAL; ++i) {
        long long points_from_taking_i = (long long)i * counts[i];
        dp[i] = max(dp[i-1], points_from_taking_i + dp[i-2]);
    }

    cout << dp[MAX_ELEMENT_VAL] << endl;

    return 0;
}