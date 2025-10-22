#include <bits/stdc++.h>
using namespace std;

// Helper to check if we can draw an edge between two nodes
bool can_connect(int num1, int num2) {
    int sum = num1 + num2;
    if (sum < 4) return false;
    for (int i = 2; i * i <= sum; ++i) {
        if (sum % i == 0) {
            return true; // Sum is composite, so they can be connected
        }
    }
    return false; // Sum is prime
}

void solve() {
    int n;
    cin >> n;

    // For n=2,3,4, the graph is disconnected, so no path exists.
    if (n <= 4) {
        cout << -1 << endl;
        return;
    }
    
    // Separate nodes into the "Even Blob" and the "Odd Blob"
    vector<int> evens, odds;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) evens.push_back(i);
        else odds.push_back(i);
    }

    // STEP 1: Walk a simple path through the Even Blob
    for (int node : evens) {
        cout << node << " ";
    }
    
    // This is the last node we visited in the Even Blob
    int last_even_node = evens.back();
    
    // STEP 2 & 3: Find a bridge and cross it
    int bridge_to_odd_node = -1;
    for (int odd_node : odds) {
        if (can_connect(last_even_node, odd_node)) {
            bridge_to_odd_node = odd_node;
            break;
        }
    }
    
    cout << bridge_to_odd_node << " ";
    
    // STEP 4: Walk through the rest of the Odd Blob
    for (int node : odds) {
        if (node != bridge_to_odd_node) {
            cout << node << " ";
        }
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