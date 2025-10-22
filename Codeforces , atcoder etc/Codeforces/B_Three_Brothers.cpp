#include <iostream>

void solve() {
    int a, b;
    std::cin >> a >> b;
    
    // The sum of all brother numbers is 1 + 2 + 3 = 6.
    // The missing number is 6 minus the two given numbers.
    std::cout << 6 - a - b << std::endl;
}

int main() {
    // This problem doesn't have multiple test cases.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}