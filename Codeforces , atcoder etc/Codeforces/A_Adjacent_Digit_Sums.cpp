#include <iostream>

// Function to solve a single test case
void solve() {
    int x, y;
    std::cin >> x >> y;
    
    // Calculate the difference required by the logic
    int diff = x - y + 1;
    
    // Check if a valid n can exist based on the logic derived
    // 1. y must not be greater than x + 1, which means diff must be non-negative.
    // 2. The difference (x - y + 1) must be a multiple of 9.
    if (diff >= 0 && diff % 9 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}