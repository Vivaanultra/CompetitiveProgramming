#include <iostream>

// Solve function for a single test case
void solve() {
    int n;
    std::cin >> n;

    long long max_sum = -1; // Use long long to prevent overflow for sum
    int optimal_x = -1;

    // Iterate through all possible values of x from 2 to n
    for (int x = 2; x <= n; ++x) {
        long long current_sum = 0;
        // Calculate the sum of all multiples of x up to n
        for (int m = x; m <= n; m += x) {
            current_sum += m;
        }

        // If the sum for the current x is greater than the max sum found so far
        if (current_sum > max_sum) {
            max_sum = current_sum;
            optimal_x = x;
        }
    }
    std::cout << optimal_x << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}