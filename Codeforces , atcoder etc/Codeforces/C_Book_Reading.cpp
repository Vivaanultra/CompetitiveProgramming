#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Using the standard namespace

// Function to solve a single query
void solve() {
    long long n, m; // n: total pages, m: divisor
    cin >> n >> m;

    // Calculate how many numbers are divisible by m up to n
    long long k = n / m;

    if (k == 0) {
        cout << 0 << endl; // If no numbers are divisible, sum is 0
        return;
    }

    vector<int> pattern_last_digits; // To store the last digits of m*1, m*2, ..., m*10
    long long sum_of_pattern = 0;    // Sum of these 10 last digits

    // Generate the pattern of the first 10 last digits
    for (int i = 1; i <= 10; ++i) {
        long long current_multiple = m * i;
        int last_digit = current_multiple % 10;
        pattern_last_digits.push_back(last_digit);
        sum_of_pattern += last_digit;
    }

    // Calculate how many full cycles of this 10-digit pattern exist
    long long num_full_cycles = k / 10;
    long long total_sum = num_full_cycles * sum_of_pattern;

    // Calculate the number of remaining terms after the full cycles
    int remaining_terms = k % 10;

    // Add the sum of last digits for the remaining terms
    for (int i = 0; i < remaining_terms; ++i) {
        total_sum += pattern_last_digits[i];
    }

    cout << total_sum << endl; // Print the final sum
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; // Number of queries
    cin >> q;
    while (q--) {
        solve(); // Solve each query
    }
    return 0;
}