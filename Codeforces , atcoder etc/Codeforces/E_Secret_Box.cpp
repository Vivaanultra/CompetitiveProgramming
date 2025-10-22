#include <iostream>
#include <algorithm>
#include <vector>

// Using competitive programming practices
#include <bits/stdc++.h>
using namespace std;

// This function calculates the maximum placements for a fixed orientation.
// It iterates through all possible dimensions 'a' and 'b' that fit within
// the provided 'dim1' and 'dim2', calculates 'c', and checks if it fits in 'dim3'.
long long calculate_max_placements(long long dim1, long long dim2, long long dim3, long long k) {
    long long max_p = 0;

    for (long long a = 1; a <= dim1; ++a) {
        // Check if 'a' is a factor of k
        if (k % a == 0) {
            long long k_prime = k / a;
            // Iterate through possible 'b' values
            for (long long b = 1; b <= dim2; ++b) {
                // Check if 'b' is a factor of the remaining volume
                if (k_prime % b == 0) {
                    long long c = k_prime / b;
                    // Check if the final dimension 'c' fits
                    if (c <= dim3) {
                        long long placements = (dim1 - a + 1) * (dim2 - b + 1) * (dim3 - c + 1);
                        if (placements > max_p) {
                            max_p = placements;
                        }
                    }
                }
            }
        }
    }
    return max_p;
}

void solve() {
    long long x, y, z, k;
    cin >> x >> y >> z >> k;

    long long max_ans = 0;

    // The problem is symmetric. A box with dimensions (d1, d2, d3) might fit
    // if d1 is along x, d2 along y, etc., but also if d1 is along y, d2 along z...
    // A simple way to check all orientations is to rotate the outer box B's dimensions
    // and run the same logic. This covers all unique permutations.
    max_ans = max(max_ans, calculate_max_placements(x, y, z, k));
    max_ans = max(max_ans, calculate_max_placements(y, z, x, k));
    max_ans = max(max_ans, calculate_max_placements(z, x, y, k));

    cout << max_ans << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}