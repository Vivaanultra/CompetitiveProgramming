#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Using competitive programming template style
#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 100005;
vector<int> primes;
bool is_prime[N_MAX];

/**
 * @brief Precomputes prime numbers up to N_MAX using a Sieve.
 */
void sieve() {
    fill(is_prime, is_prime + N_MAX, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < N_MAX; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i < N_MAX; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p < N_MAX; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

/**
 * @brief Solves a single test case using prime factorization cycles.
 */
void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<bool> used(n + 1, false);

    // Iterate through primes from LARGEST to SMALLEST.
    // This is the critical step to ensure correctness.
    for (int j = primes.size() - 1; j >= 0; --j) {
        int pr = primes[j];
        if (pr > n) continue;
        
        vector<int> bucket;
        // Collect all multiples of the current prime that haven't been used yet.
        for (long long i = pr; i <= n; i += pr) {
            if (!used[i]) {
                bucket.push_back(i);
            }
        }

        // If we found multiples, form a cycle.
        if (bucket.size() > 1) {
            for (size_t i = 0; i < bucket.size(); ++i) {
                // p[current] = next. The last element cycles to the first.
                p[bucket[i]] = bucket[(i + 1) % bucket.size()];
                used[bucket[i]] = true;
            }
        }
    }
    
    // Any number not used in a cycle becomes a fixed point.
    // This includes 1 and primes > n/2.
    for(int i = 1; i <= n; ++i) {
        if (!used[i]) {
            p[i] = i;
        }
    }

    // Print the resulting permutation.
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute primes once.
    sieve();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}