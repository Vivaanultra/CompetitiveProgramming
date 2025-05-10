#include <iostream> // Include the input/output stream library

int main() {
    // Optimize input/output operations for faster execution.
    // std::ios_base::sync_with_stdio(false); synchronizes C++ standard streams with C stdio streams. Setting it to false can speed up I/O.
    // std::cin.tie(NULL); unties cin from cout, meaning the program won't flush cout before reading from cin, which can also improve speed.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    std::cin >> t; // Read the number of test cases from the input.

    // Loop through each test case.
    while (t--) {
        long long n; // Declare a long long variable 'n' to store the length of the permutation.
                     // Using long long is safer in case n*n exceeds the capacity of a standard int, although for n<=500, int would suffice.
        std::cin >> n; // Read the length of the permutation for the current test case.

        /*
         * Problem Analysis:
         * We are given a function f(p) = sum(|p[i] - i|) for i from 1 to n, where p is a permutation of [1, ..., n].
         * We need to find the number of distinct values f(p) can take over all possible permutations p.
         *
         * Key Properties of f(p):
         * 1. Minimum Value: f(p) = 0 for the identity permutation p = [1, 2, ..., n].
         * 2. Maximum Value: f(p) reaches its maximum for the reversed permutation p = [n, n-1, ..., 1].
         * The maximum value M is floor(n*n / 2).
         * - If n is even (n=2k), M = n*n / 2 = 2*k*k.
         * - If n is odd (n=2k+1), M = (n*n - 1) / 2 = 2*k*(k+1).
         * 3. Parity: f(p) is always an even number. This is because sum(p[i] - i) = sum(p[i]) - sum(i) = 0,
         * and f(p) = sum(|p[i] - i|) has the same parity as sum(p[i] - i). So, f(p) % 2 == 0.
         *
         * Range of Values:
         * Based on a known result (e.g., from Diaconis and Graham, 1977), the function f(p) can achieve *all* even integer values
         * between its minimum (0) and its maximum (M = floor(n*n / 2)).
         * So, the set of distinct values is {0, 2, 4, ..., M}.
         *
         * Counting Distinct Values:
         * We need to count how many numbers are in the set {0, 2, 4, ..., M}.
         * This is equivalent to counting {0, 1, 2, ..., M/2}.
         * The number of values is M/2 + 1.
         *
         * Calculation using n:
         * - If n is even (n=2k): M = 2*k*k. Number of values = (2*k*k)/2 + 1 = k*k + 1.
         * Since k = n/2, this is (n/2)*(n/2) + 1 = n*n / 4 + 1.
         * - If n is odd (n=2k+1): M = 2*k*(k+1). Number of values = (2*k*(k+1))/2 + 1 = k*(k+1) + 1 = k*k + k + 1.
         * Let's express this using n*n / 4 (integer division):
         * n*n / 4 = (2k+1)*(2k+1) / 4 = (4k*k + 4k + 1) / 4 = k*k + k (integer division discards the remainder 1/4).
         * So, n*n / 4 + 1 = (k*k + k) + 1.
         *
         * Combined Formula:
         * In both even and odd cases, the number of distinct values can be calculated using integer division as (n * n) / 4 + 1.
         */

        // Calculate the number of distinct values using the derived formula.
        // Integer division `(n * n) / 4` handles both even and odd cases correctly.
        long long distinct_values = (n * n) / 4 + 1;

        // Output the calculated number of distinct values for the current test case, followed by a newline character.
        std::cout << distinct_values << "\n";
    }

    return 0; // Indicate successful program execution.
}