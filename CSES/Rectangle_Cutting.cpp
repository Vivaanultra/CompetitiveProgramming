#include <bits/stdc++.h>
using namespace std;

// Infinity constant
const int INF = 1e9;
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (!(cin >> a >> b)) return 0;

    for (int w = 1; w <= a; w++) {
        for (int h = 1; h <= b; h++) {
            // Base Case: It's already a square
            if (w == h) {
                dp[w][h] = 0;
            } else {
                dp[w][h] = INF;
                
                // Option 1: Vertical Cuts
                // We only need to check up to w/2 due to symmetry
                for (int i = 1; i <= w / 2; i++) {
                    dp[w][h] = min(dp[w][h], 1 + dp[i][h] + dp[w-i][h]);
                }

                // Option 2: Horizontal Cuts
                // We only need to check up to h/2 due to symmetry
                for (int j = 1; j <= h / 2; j++) {
                    dp[w][h] = min(dp[w][h], 1 + dp[w][j] + dp[w][h-j]);
                }
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}