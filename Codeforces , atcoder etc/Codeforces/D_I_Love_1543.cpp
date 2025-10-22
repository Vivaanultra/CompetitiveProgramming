#include <bits/stdc++.h>

// Using std namespace for competitive programming convenience
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> carpet(n);
    for (int i = 0; i < n; ++i) {
        cin >> carpet[i];
    }

    long long total_occurrences = 0;
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    // Process the carpet layer by layer from the outside in
    while (top < bottom && left < right) {
        string layer_sequence = "";

        // 1. Traverse top edge (left to right)
        for (int j = left; j < right; ++j) {
            layer_sequence += carpet[top][j];
        }
        // 2. Traverse right edge (top to bottom)
        for (int i = top; i < bottom; ++i) {
            layer_sequence += carpet[i][right];
        }
        // 3. Traverse bottom edge (right to left)
        for (int j = right; j > left; --j) {
            layer_sequence += carpet[bottom][j];
        }
        // 4. Traverse left edge (bottom to top)
        for (int i = bottom; i > top; --i) {
            layer_sequence += carpet[i][left];
        }

        if (layer_sequence.length() < 4) {
            // If layer is too small, no "1543" can be formed
            break;
        }

        // Create a search string to handle circular wraparound cases
        string search_string = layer_sequence + layer_sequence.substr(0, 3);

        // Count occurrences of "1543" in the layer's sequence
        for (size_t i = 0; i <= search_string.length() - 4; ++i) {
            if (search_string.substr(i, 4) == "1543") {
                total_occurrences++;
            }
        }
        
        // Move to the next inner layer
        top++;
        bottom--;
        left++;
        right--;
    }

    cout << total_occurrences << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}