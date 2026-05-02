#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> s;
int memo[1005][1005];
int mod = 1e9 + 7;

int solve(int r, int c) {
    if (r >= n || c >= n || s[r][c] == '*') return 0;
    if (r == n - 1 && c == n - 1) return 1;
    if (memo[r][c] != -1) return memo[r][c];
    return memo[r][c] = (solve(r + 1, c) + solve(r, c + 1)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    memset(memo, -1, sizeof(memo));
    cout << solve(0, 0) << endl;
    return 0;
}