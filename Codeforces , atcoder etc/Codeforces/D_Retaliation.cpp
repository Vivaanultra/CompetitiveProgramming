#include <iostream>
#include <vector>
#include <numeric>

// Include all standard libraries for competitive programming
#include <bits/stdc++.h>
// Use the standard namespace
using namespace std;

// Function to solve a single test case
void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Let x = number of type 1 operations, y = number of type 2 operations.
    // For each element a[i] (using 1-based index i), we need:
    // a_i = x*i + y*(n-i+1)

    // We use the first (i=1) and last (i=n) elements to solve for x and y.
    // Note: In our 0-indexed vector, a_1 is a[0] and a_n is a[n-1].
    long long first_element = a[0];
    long long last_element = a[n - 1];

    // Denominator for solving the system of equations is n^2 - 1.
    // Since n >= 2, the denominator is never zero.
    long long denominator = n * n - 1;

    // Numerators for x and y derived from solving the system of equations.
    long long numerator_y = n * first_element - last_element;
    long long numerator_x = n * last_element - first_element;

    // Check if x and y can be non-negative integers.
    // 1. Numerators must be non-negative.
    // 2. Numerators must be perfectly divisible by the denominator.
    if (numerator_x < 0 || numerator_y < 0 || numerator_x % denominator != 0 || numerator_y % denominator != 0) {
        cout << "NO\n";
        return;
    }

    // Calculate the integer values of x and y.
    long long x = numerator_x / denominator;
    long long y = numerator_y / denominator;

    // Verify if these x and y values hold for all elements in the array.
    for (int i = 0; i < n; ++i) {
        // The index for the formula is 1-based.
        long long one_based_index = i + 1;
        if (a[i] != x * one_based_index + y * (n - one_based_index + 1)) {
            cout << "NO\n";
            return;
        }
    }

    // If all checks passed, it's possible to explode the array.
    cout << "YES\n";
}

int main() {
    // Fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}