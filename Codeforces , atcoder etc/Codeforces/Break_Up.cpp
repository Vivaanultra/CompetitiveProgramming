#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<vector<bool>> is_palindrome;
vector<int> memo;

int solve(int start_index) {
    if (start_index >= n) {
        return 0;
    }
    if (memo[start_index] != -1) {
        return memo[start_index];
    }

    int min_partitions = n;
    for (int j = start_index; j < n; ++j) {
        if (is_palindrome[start_index][j]) {
            min_partitions = min(min_partitions, 1 + solve(j + 1));
        }
    }

    return memo[start_index] = min_partitions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    is_palindrome.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        is_palindrome[i][i] = true;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            is_palindrome[i][i + 1] = true;
        }
    }
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (a[i] == a[j] && is_palindrome[i + 1][j - 1]) {
                is_palindrome[i][j] = true;
            }
        }
    }

    memo.assign(n + 1, -1);
    cout << solve(0) << "\n";

    return 0;
}