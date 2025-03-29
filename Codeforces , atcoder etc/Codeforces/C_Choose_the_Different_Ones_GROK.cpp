#include <iostream> // For input and output (cin, cout)
#include <vector>   // For using vectors (dynamic arrays)

using namespace std;

int main() {
    // Make input/output faster
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t; // Read how many test cases we have

    // Loop through each test case
    for (int test = 0; test < t; test++) {
        int n, m, k; // n = size of array a, m = size of array b, k = target number
        cin >> n >> m >> k; // Read n, m, and k for this test case

        // Create array a with size n and read its elements
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Fill array a with n numbers
        }

        // Create array b with size m and read its elements
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i]; // Fill array b with m numbers
        }

        // Create two arrays to mark which numbers from 1 to k are in a and b
        // We use k+1 size because we want indices 1 to k (index 0 is unused)
        vector<bool> in_a(k + 1, false); // false means number not present in a
        vector<bool> in_b(k + 1, false); // false means number not present in b

        // Mark numbers that are in array a
        for (int i = 0; i < n; i++) {
            // Only mark if the number is between 1 and k (we don't care about others)
            if (a[i] >= 1 && a[i] <= k) {
                in_a[a[i]] = true; // Set to true to show this number is in a
            }
        }

        // Mark numbers that are in array b
        for (int i = 0; i < m; i++) {
            // Only mark if the number is between 1 and k
            if (b[i] >= 1 && b[i] <= k) {
                in_b[b[i]] = true; // Set to true to show this number is in b
            }
        }

        // Step 1: Check if all numbers from 1 to k are in at least one array
        bool all_numbers_present = true; // Assume all numbers are there
        for (int i = 1; i <= k; i++) {
            // If a number i is not in a AND not in b, we can't cover it
            if (!in_a[i] && !in_b[i]) {
                all_numbers_present = false; // We found a missing number
                break; // No need to check further
            }
        }

        // If any number is missing, it's impossible, so print "NO" and skip to next test case
        if (!all_numbers_present) {
            cout << "NO\n";
            continue; // Move to the next test case
        }

        // Step 2: Count numbers that are ONLY in a (not in b)
        int only_in_a = 0; // Counter for numbers unique to a
        for (int i = 1; i <= k; i++) {
            if (in_a[i] && !in_b[i]) { // If i is in a but not in b
                only_in_a++; // Increase the count
            }
        }

        // Count numbers that are ONLY in b (not in a)
        int only_in_b = 0; // Counter for numbers unique to b
        for (int i = 1; i <= k; i++) {
            if (in_b[i] && !in_a[i]) { // If i is in b but not in a
                only_in_b++; // Increase the count
            }
        }

        // Step 3: Check if we can choose k/2 elements from each array
        int half_k = k / 2; // We need to pick exactly k/2 from a and k/2 from b
        // If numbers unique to a or b exceed k/2, we can't pick enough from the other array
        if (only_in_a > half_k || only_in_b > half_k) {
            cout << "NO\n"; // Impossible to cover all numbers
        } else {
            cout << "YES\n"; // Possible to cover all numbers
        }
    }

    return 0; // Program ends successfully
}