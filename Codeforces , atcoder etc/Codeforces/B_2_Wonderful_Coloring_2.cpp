#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    // Use a map to group elements by value, storing their original indices
    map<int, vector<int>> positions;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        positions[val].push_back(i);
    }

    // Collect all elements we can possibly paint (up to k of each)
    vector<int> paintable_indices;
    for (auto const& [val, pos_vec] : positions) {
        for (int i = 0; i < min((int)pos_vec.size(), k); i++) {
            paintable_indices.push_back(pos_vec[i]);
        }
    }

    // Determine the final number of elements to paint to ensure even groups
    int total_to_paint = paintable_indices.size() - (paintable_indices.size() % k);
    
    // Create the answer array, initialized to 0 (unpainted)
    vector<int> colors(n, 0);

    // Assign colors in a cycle: 1, 2, ..., k, 1, 2, ...
    for (int i = 0; i < total_to_paint; i++) {
        int original_index = paintable_indices[i];
        int color_to_assign = (i % k) + 1;
        colors[original_index] = color_to_assign;
    }

    // Print the final coloring
    for (int i = 0; i < n; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;
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