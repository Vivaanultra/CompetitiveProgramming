#include <iostream>
#include <vector>
#include <bits/stdc++.h>

// Using standard namespace for competitive programming
using namespace std;

// A class to represent the park and solve the problem
class Park {
private:
    int n; // Number of vertices in the park
    int m; // Maximum allowed consecutive cats
    vector<int> has_cat; // Stores 1 if a vertex has a cat, 0 otherwise
    vector<vector<int>> adj; // Adjacency list to represent the tree
    int valid_restaurants; // Counter for valid restaurants

    /**
     * @brief Performs a Depth First Search to find valid paths to restaurants.
     * @param u The current vertex being visited.
     * @param p The parent of the current vertex in the traversal.
     * @param consecutive_cats The count of consecutive cats on the path from the root to the parent 'p'.
     */
    void dfs(int u, int p, int consecutive_cats) {
        // Update the count of consecutive cats for the current vertex 'u'
        int current_consecutive_cats;
        if (has_cat[u] == 1) {
            current_consecutive_cats = consecutive_cats + 1;
        } else {
            current_consecutive_cats = 0; // Reset the counter if there's no cat
        }

        // If the number of consecutive cats exceeds the limit, this path is invalid.
        // We stop exploring this branch further.
        if (current_consecutive_cats > m) {
            return;
        }

        // A flag to check if the current vertex 'u' is a leaf node.
        // A node is a leaf if it has no children in the rooted tree structure.
        bool is_leaf = true;

        // Recursively visit all adjacent vertices (children)
        for (int v : adj[u]) {
            // We ensure we don't go back to the parent vertex
            if (v != p) {
                is_leaf = false; // If 'u' has a child, it's not a leaf
                dfs(v, u, current_consecutive_cats);
            }
        }

        // If the current vertex 'u' is a leaf and the path to it is valid,
        // we count it as a valid restaurant.
        if (is_leaf) {
            valid_restaurants++;
        }
    }

public:
    // Constructor to initialize the counter
    Park() : valid_restaurants(0) {}

    // Main function to read input and trigger the solution
    void solve() {
        // Read the number of vertices and the cat limit
        cin >> n >> m;

        // Resize data structures based on input size 'n'
        // We use n+1 for 1-based indexing
        has_cat.resize(n + 1);
        adj.resize(n + 1);

        // Read the cat information for each vertex
        for (int i = 1; i <= n; ++i) {
            cin >> has_cat[i];
        }

        // Read the n-1 edges to build the tree
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            // An edge connects u and v, so we add each to the other's adjacency list
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Start the DFS from Kefa's house (vertex 1).
        // The parent of the root is a dummy node (e.g., 0).
        // The initial number of consecutive cats is 0.
        dfs(1, 0, 0);

        // Print the final count of reachable restaurants
        cout << valid_restaurants << endl;
    }
};

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Create a Park object and run the solver
    Park kefa_park;
    kefa_park.solve();

    return 0;
}