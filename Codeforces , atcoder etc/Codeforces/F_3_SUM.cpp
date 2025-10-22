#include <iostream>
#include <vector>
#include <numeric>

// Including the entire standard library for convenience in competitive programming.
#include <bits/stdc++.h>

// Using the standard namespace to avoid typing std:: repeatedly.
using namespace std;

// This function solves a single test case of the problem.
void solve() {
    int n;
    cin >> n; // Read the number of elements in the array.

    // We only need the last digit of the numbers. Since we are looking for a sum of three numbers,
    // we will never need more than three numbers that have the same last digit.
    // For example, to get a sum ending in 3 like 1+1+1=3, we need three 1s. A fourth 1 would be redundant.
    // So, we filter the input and only keep up to three numbers for each possible last digit (0-9).
    vector<int> counts(10, 0);
    vector<int> candidates;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        int last_digit = a % 10;
        // Add the last digit to our candidate list if we have seen this last digit less than 3 times.
        if (counts[last_digit] < 3) {
            counts[last_digit]++;
            candidates.push_back(last_digit);
        }
    }

    // Now, 'candidates' contains a much smaller set of numbers to check (at most 30).
    // We can perform a brute-force check on this smaller list.
    int m = candidates.size();
    bool found = false;

    // Iterate through all unique combinations of three distinct indices i, j, k.
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                // Check if the sum of the last digits at these indices ends in 3.
                if ((candidates[i] + candidates[j] + candidates[k]) % 10 == 3) {
                    found = true; // A valid combination is found.
                    break; // Exit the innermost loop.
                }
            }
            if (found) {
                break; // Exit the middle loop.
            }
        }
        if (found) {
            break; // Exit the outermost loop.
        }
    }

    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Standard competitive programming setup for fast I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases.
    while (t--) {
        solve();
    }

    return 0;
}