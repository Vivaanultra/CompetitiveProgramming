#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm> // For std::min, std::max
#include <utility>   // For std::pair

// Using long long for battery counts as they can be large. Max w_i or b_i is 10^9.
const long long INF = 4e18; // A large enough value for infinity (Approx 4 * 10^18)

struct State {
    long long batteries_on_arrival;
    int checkpoint_id;

    // Custom comparator for min-priority queue:
    // Sorts by batteries_on_arrival ascending, then by checkpoint_id ascending for tie-breaking.
    bool operator>(const State& other) const {
        if (batteries_on_arrival != other.batteries_on_arrival) {
            return batteries_on_arrival > other.batteries_on_arrival;
        }
        return checkpoint_id > other.checkpoint_id; 
    }
};

void solve() {
    int n; // number of checkpoints
    int m; // number of passages
    std::cin >> n >> m;

    std::vector<long long> b(n + 1); // batteries available at checkpoint i
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }

    // Adjacency list: adj[u] stores pairs of {v, w_edge} for passages u -> v requiring w_edge batteries.
    // w_edge stored as int, as its max value 10^9 fits. Cast to long long in calculations.
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1); 
    for (int i = 0; i < m; ++i) {
        int u_node, v_node, w_cost;
        std::cin >> u_node >> v_node >> w_cost;
        adj[u_node].push_back({v_node, w_cost});
    }

    long long min_total_batteries_at_N = INF;
    
    // Stores {batteries_on_arrival, checkpoint_id} for states that have been popped and processed.
    std::set<std::pair<long long, int>> processed_states; 

    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    // Initial state: at checkpoint 1 with 0 batteries.
    pq.push({0, 1});

    while (!pq.empty()) {
        State current_state = pq.top();
        pq.pop();

        long long C_u = current_state.batteries_on_arrival;
        int u = current_state.checkpoint_id;

        // Pruning 1: If current batteries C_u are already >= best known result for N,
        // and we are not at N itself, this path cannot be better.
        if (u != n && C_u >= min_total_batteries_at_N) {
             continue;
        }
        
        // If this exact state (u with C_u batteries) has already been processed, skip.
        // This check is vital for correctness and performance.
        if (processed_states.count({C_u, u})) {
            continue;
        }
        processed_states.insert({C_u, u}); // Mark current state as processed.

        // If checkpoint N is reached:
        if (u == n) {
            min_total_batteries_at_N = std::min(min_total_batteries_at_N, C_u);
            // No further passages to explore from N for this path.
            continue; 
        }
        
        // Explore neighbors for u (which is not n at this point):
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w_edge_val = edge.second; // Min batteries needed for passage (u,v)

            long long min_pickup_needed = 0;
            if ((long long)w_edge_val > C_u) { // Need to pick up batteries
                min_pickup_needed = (long long)w_edge_val - C_u;
            }

            if (min_pickup_needed > b[u]) { // Cannot pick up enough batteries at u
                continue; 
            }

            long long batteries_at_v_arrival = std::max(C_u, (long long)w_edge_val);
            
            // Pruning 2: If this new state (C_v, v) would result in batteries_at_v_arrival
            // that's already GTE a known path to N (and v is not N itself), do not push.
            if (v != n && batteries_at_v_arrival >= min_total_batteries_at_N) {
                continue;
            }
            // If v == n, we always push it (if valid). It will be handled if/when popped,
            // potentially updating min_total_batteries_at_N.
            
            // No need to check processed_states before push; duplicates in PQ are fine.
            // They'll be filtered by the check at the start of the loop when popped.
            pq.push({batteries_at_v_arrival, v});
        }
    }

    if (min_total_batteries_at_N == INF) {
        std::cout << -1 << "\n";
    } else {
        std::cout << min_total_batteries_at_N << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}