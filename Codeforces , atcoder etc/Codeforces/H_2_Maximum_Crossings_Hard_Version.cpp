#include <bits/stdc++.h>

using namespace std;

// The MAXN must be large enough for the hard version's constraints.
const int MAXN = 200005;
int bit[MAXN];

// Adds 1 to the count for value `idx`.
// The `idx += idx & -idx` is a bitwise trick to quickly
// jump to the next relevant "summary" cell in the tree.
void update(int idx, int val) {
    for (; idx < MAXN; idx += idx & -idx) {
        bit[idx] += val;
    }
}

// Gets the total count of numbers seen with values up to `idx`.
// The `idx -= idx & -idx` trick quickly sums up the necessary summary cells.
int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    
    // We must keep track of which indices we update to clear them later.
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_crossings = 0;
    
    for (int i = 0; i < n; ++i) {
        // We need to count wires j < i where a[j] >= a[i].
        // This is (total wires seen so far) - (wires where a[j] < a[i]).
        
        int total_seen_so_far = i;
        
        // Query for numbers strictly smaller than a[i].
        int count_smaller = query(a[i] - 1);
        
        total_crossings += (total_seen_so_far - count_smaller);
        
        // Add the current wire's endpoint to the tree for the next iterations.
        update(a[i], 1);
    }

    // Crucially, we must reset the Fenwick tree for the next test case.
    // We only need to clear the indices we actually used.
    for (int i = 0; i < n; ++i) {
        update(a[i], -1);
    }
    
    cout << total_crossings << endl;
}

int main() {
    // It is currently Sunday, 6:55 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}