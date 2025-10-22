#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

// Per your preference, including bits/stdc++.h and using namespace std.
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> s(n);
    
    // Use a set to store unvisited dominoes, sorted by size.
    // The set stores pairs of {size, original_index}.
    set<pair<long long, int>> unvisited_dominoes;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        // Any domino except the starting one (domino 1) is a potential next step.
        if (i != 0) {
            unvisited_dominoes.insert({s[i], i});
        }
    }

    // dist[i] will store the minimum number of dominoes in a chain to reach domino i+1.
    vector<int> dist(n, -1);
    // Standard BFS queue to hold indices of dominoes to visit.
    queue<int> q;

    // The path starts with domino 1 (index 0). It's a chain of length 1.
    dist[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // The toppling power of the current domino u.
        long long topple_power = 2 * s[u];

        // Find the boundary for findable neighbors in the sorted set.
        // We look for the first element strictly greater than {topple_power, n}.
        // The second element of the pair (n) is a large value to ensure we get all dominoes with size equal to topple_power.
        auto end_it = unvisited_dominoes.upper_bound({topple_power, n});

        // Add all found neighbors to the queue and update their distance.
        for (auto it = unvisited_dominoes.begin(); it != end_it; ++it) {
            int v_idx = it->second;
            dist[v_idx] = dist[u] + 1;
            q.push(v_idx);
        }
        
        // Efficiently remove all the neighbors we just processed from the unvisited set.
        unvisited_dominoes.erase(unvisited_dominoes.begin(), end_it);
    }

    // The result is the shortest path length to domino N (index n-1).
    // If it was never reached, dist[n-1] remains -1.
    cout << dist[n - 1] << endl;
}

int main() {
    // Fast I/O for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}