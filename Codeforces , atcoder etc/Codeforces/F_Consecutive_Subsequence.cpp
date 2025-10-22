#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> dp;
    int max_length = 0;
    int end_value = -1;

    for (int val : a) {
        dp[val] = dp[val - 1] + 1;
        if (dp[val] > max_length) {
            max_length = dp[val];
            end_value = val;
        }
    }

    cout << max_length << "\n";

    vector<int> result_indices;
    int current_needed_value = end_value;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == current_needed_value) {
            result_indices.push_back(i + 1);
            current_needed_value--;
        }
    }

    reverse(result_indices.begin(), result_indices.end());

    for (int i = 0; i < result_indices.size(); ++i) {
        cout << result_indices[i] << (i == result_indices.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}