#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    // Use a boolean vector or frequency array to track presence of numbers.
    // Size n + 2 ensures we cover 0 to n+1 safely.
    vector<int> present(n + 2, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= n) {
            present[a[i]] = 1;
        }
    }
    
    // Calculate Initial MEX
    int initial_mex = 0;
    while (present[initial_mex]) {
        initial_mex++;
    }
    
    // The answer is the minimum of the initial MEX and the maximum possible MEX given the final size (k-1)
    cout << min(initial_mex, k - 1) << "\n";
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