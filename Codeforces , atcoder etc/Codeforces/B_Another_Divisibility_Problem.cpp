#include <iostream>

void solve() {
    long long x;
    std::cin >> x;
    std::cout << 2 * x << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}