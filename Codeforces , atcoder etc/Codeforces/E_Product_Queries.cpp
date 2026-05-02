#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool has_one = false;
    
    // Use a set to handle duplicates and sorting automatically
    set<int> unique_vals;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) has_one = true;
        else if(a[i] <= n) unique_vals.insert(a[i]);
    }

    // Convert to vector for indexed access
    vector<int> multipliers(unique_vals.begin(), unique_vals.end());
    
    // dist[i] stores min elements to get product i
    vector<int> dist(n + 1, -1);
    queue<int> q;

    // Initialize BFS with single elements
    for(int x : multipliers) {
        dist[x] = 1;
        q.push(x);
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int m : multipliers) {
            // Check for overflow before multiplication
            if((long long)u * m > n) break; 
            
            int next_val = u * m;
            
            if(dist[next_val] == -1) {
                dist[next_val] = dist[u] + 1;
                q.push(next_val);
            }
        }
    }

    // Output results
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            cout << (has_one ? 1 : -1) << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}