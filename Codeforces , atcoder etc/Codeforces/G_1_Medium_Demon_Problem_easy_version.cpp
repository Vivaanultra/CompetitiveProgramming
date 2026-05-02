#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> r(n + 1);
    vector<int> indegree(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
        indegree[r[i]]++;
    }

    
    queue<int> q;
    
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] = 1; 
        }
    }

    int max_chain_len = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        
        max_chain_len = max(max_chain_len, dp[u]);

        int v = r[u];
        
        
        
        dp[v] = max(dp[v], dp[u] + 1);
        
        indegree[v]--;
        if (indegree[v] == 0) {
            q.push(v);
        }
    }

    
    
    cout << max_chain_len + 2 << "\n";
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