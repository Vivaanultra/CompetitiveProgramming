#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Use long long for values as they can be up to 10^9
using namespace std;

/**
 * @brief Solves a single test case.
 */
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long x;
    cin >> x;

    // Base case: If n=1, no operations are performed.
    // The final number is just a[0].
    if (n == 1) {
        if (a[0] == x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    // Precompute prefix minimums and maximums
    // minL[i] = min(a[0]...a[i])
    // maxL[i] = max(a[0]...a[i])
    vector<long long> minL(n);
    vector<long long> maxL(n);
    minL[0] = a[0];
    maxL[0] = a[0];
    for (int i = 1; i < n; ++i) {
        minL[i] = min(minL[i - 1], a[i]);
        maxL[i] = max(maxL[i - 1], a[i]);
    }

    // Precompute suffix minimums and maximums
    // minR[i] = min(a[i]...a[n-1])
    // maxR[i] = max(a[i]...a[n-1])
    vector<long long> minR(n);
    vector<long long> maxR(n);
    minR[n - 1] = a[n - 1];
    maxR[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        minR[i] = min(minR[i + 1], a[i]);
        maxR[i] = max(maxR[i + 1], a[i]);
    }

    bool found = false;
    // Iterate through all possible split points 'k'.
    // The left part is a[0...k]
    // The right part is a[k+1...n-1]
    for (int k = 0; k < n - 1; ++k) {
        // Check if left part has an element <= x
        bool L_has_le = (minL[k] <= x);
        // Check if left part has an element >= x
        bool L_has_ge = (maxL[k] >= x);
        
        // Check if right part has an element <= x
        bool R_has_le = (minR[k + 1] <= x);
        // Check if right part has an element >= x
        bool R_has_ge = (maxR[k + 1] >= x);

        // Condition 1: Can we pick L <= x and R >= x?
        if (L_has_le && R_has_ge) {
            found = true;
            break;
        }
        
        // Condition 2: Can we pick L >= x and R <= x?
        if (L_has_ge && R_has_le) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}