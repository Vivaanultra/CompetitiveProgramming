#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> coins;

vector<int> memo; 

int solve(int current_sum) {
    
    if (current_sum == 0) return 0;
    
    
    if (current_sum < 0) return 1e9; 
    
    
    if (memo[current_sum] != -1) return memo[current_sum];
    
    int best = 1e9;
    for (int c : coins) {
        best = min(best, solve(current_sum - c) + 1);
    }
    
    
    return memo[current_sum] = best;
}

int main() {
    cin >> n >> x;
    coins.resize(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    
    memo.assign(x + 1, -1);
    
    int ans = solve(x);
    
    if (ans >= 1e9) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}