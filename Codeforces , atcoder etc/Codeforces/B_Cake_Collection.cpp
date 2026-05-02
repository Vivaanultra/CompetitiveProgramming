#include <iostream>
#include <vector>
#include <algorithm>

// Function to solve a single test case
void solve() {
    int n;
    long long m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    // Sort the baking rates in descending order
    std::sort(a.rbegin(), a.rend());
    
    long long total_cakes = 0;
    
    // We can assign at most min(n, m) ovens a unique "last collection time"
    int k = std::min(n, (int)m); 
    
    // Pair the largest rates with the latest times
    for (int i = 0; i < k; ++i) {
        // The i-th largest oven (a[i]) gets the (m-i)-th latest time
        long long last_collection_time = m - i;
        total_cakes += (long long)a[i] * last_collection_time;
    }
    
    std::cout << total_cakes << "\n";
}

int main() {
    // Optimize C++ input/output streams
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}