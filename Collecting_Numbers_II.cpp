#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Use 1-based indexing for convenience
    vector<int> v(n + 1);
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    // Calculate initial answer
    int ans = 1; // Always at least 1 round
    for (int i = 1; i < n; i++) {
        // If i+1 appears before i, it starts a new round
        if (pos[i + 1] < pos[i]) {
            ans++;
        }
    }

    while (m--) {
        int r1, r2;
        cin >> r1 >> r2;

        int val1 = v[r1];
        int val2 = v[r2];

        // Identify potentially affected values.
        // We check the condition "pos[k] < pos[k-1]" for these specific k's.
        // Using a set automatically handles duplicates (e.g. if val1 and val2 are neighbors).
        set<int> candidates;
        candidates.insert(val1);
        candidates.insert(val1 + 1);
        candidates.insert(val2);
        candidates.insert(val2 + 1);

        // 1. Subtract the contribution of the OLD positions
        for (int k : candidates) {
            if (k > 1 && k <= n) { // Boundary check
                if (pos[k] < pos[k - 1]) {
                    ans--;
                }
            }
        }

        // 2. Perform the swap
        swap(v[r1], v[r2]);
        pos[val1] = r2; 
        pos[val2] = r1; 

        // 3. Add the contribution of the NEW positions
        for (int k : candidates) {
            if (k > 1 && k <= n) {
                if (pos[k] < pos[k - 1]) {
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}