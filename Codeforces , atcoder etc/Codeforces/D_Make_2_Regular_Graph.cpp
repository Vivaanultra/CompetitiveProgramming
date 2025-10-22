#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

// Using a standard competitive programming setup
#include <bits/stdc++.h>
using namespace std;

// Global variables for convenience
int n, m;
bool adj[8][8];
vector<int> cycle_cost;
vector<int> dp;

// Precomputes the max number of original edges for a single cycle on each subset of vertices
void precompute_cycle_costs() {
    cycle_cost.assign(1 << n, -1); // -1 indicates impossibility

    // Iterate through all subsets of vertices
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<int> verts;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                verts.push_back(i);
            }
        }

        int k = verts.size();
        if (k < 3) continue; // A cycle needs at least 3 vertices

        // TSP-style DP to find the best Hamiltonian cycle for the current subset `verts`
        // tsp_dp[submask][end_node_local_idx]
        vector<vector<int>> tsp_dp(1 << k, vector<int>(k, -1));
        
        // Let the path start at the first vertex of the subset (local index 0)
        tsp_dp[1][0] = 0;

        for (int sub = 1; sub < (1 << k); ++sub) {
            for (int u_local = 0; u_local < k; ++u_local) {
                if (!((sub >> u_local) & 1) || tsp_dp[sub][u_local] == -1) continue;

                for (int v_local = 0; v_local < k; ++v_local) {
                    if ((sub >> v_local) & 1) continue;

                    int u_global = verts[u_local];
                    int v_global = verts[v_local];
                    
                    int new_sub = sub | (1 << v_local);
                    // Update path cost if we extend it from u to v
                    if (adj[u_global][v_global]) {
                         tsp_dp[new_sub][v_local] = max(tsp_dp[new_sub][v_local], tsp_dp[sub][u_local] + 1);
                    } else {
                         tsp_dp[new_sub][v_local] = max(tsp_dp[new_sub][v_local], tsp_dp[sub][u_local]);
                    }
                }
            }
        }
        
        // Complete the cycle by connecting the path's end back to the start
        int final_mask = (1 << k) - 1;
        int max_c = -1;
        int start_global = verts[0];
        for (int end_local = 0; end_local < k; ++end_local) {
            if (tsp_dp[final_mask][end_local] != -1) {
                int end_global = verts[end_local];
                if (adj[end_global][start_global]) {
                    max_c = max(max_c, tsp_dp[final_mask][end_local] + 1);
                } else {
                    max_c = max(max_c, tsp_dp[final_mask][end_local]);
                }
            }
        }
        cycle_cost[mask] = max_c;
    }
}

void solve() {
    cin >> n >> m;
    memset(adj, false, sizeof(adj));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u][v] = adj[v][u] = true;
    }

    precompute_cycle_costs();

    // Main DP to find the best partition of all N vertices into cycles
    dp.assign(1 << n, -1);
    dp[0] = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        // To compute dp[mask], we iterate through all cycle submasks `sub` of `mask`
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            // Combine a valid cycle `sub` with the solution for the rest `mask ^ sub`
            if (cycle_cost[sub] != -1 && dp[mask ^ sub] != -1) {
                 dp[mask] = max(dp[mask], dp[mask ^ sub] + cycle_cost[sub]);
            }
        }
    }

    // Maximize k (common edges) to minimize cost
    int max_common_edges = dp[(1 << n) - 1];
    
    // Cost = (M - k) + (N - k)
    int result = n + m - 2 * max_common_edges;
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}