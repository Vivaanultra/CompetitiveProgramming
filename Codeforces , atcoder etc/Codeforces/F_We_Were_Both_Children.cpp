#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Step 1: Count the frequency of each hop length.
    // We only care about hop lengths <= n, as larger hops can't be trapped.
    vector<int> counts(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= n) {
            counts[a]++;
        }
    }

    // Step 2: Calculate the number of frogs caught at each trap position.
    // trap_scores[i] will store how many frogs land on position 'i'.
    vector<int> trap_scores(n + 1, 0);
    // For each possible hop length 'i' from 1 to n...
    for (int i = 1; i <= n; i++) {
        // If there are frogs with this hop length...
        if (counts[i] > 0) {
            // ...add their count to all trap positions they will visit.
            for (int j = i; j <= n; j += i) {
                trap_scores[j] += counts[i];
            }
        }
    }

    // Step 3: Find the maximum number of frogs that can be caught.
    cout << *max_element(trap_scores.begin(), trap_scores.end()) << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}