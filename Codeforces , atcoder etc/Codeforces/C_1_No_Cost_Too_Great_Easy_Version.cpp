#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// Max value of a[i] or a[i]+1
const int MAX_VAL = 200002;
// Use a large value for INF (max n is 2e5)
const long long INF = 200007;

// Global Sieve Array
vector<int> spf;

// Global array to store {min_cost, second_min_cost} for each prime
// Initialized once in main
vector<pair<long long, long long>> min_prime_costs;

/**
 * @brief Precomputes the Smallest Prime Factor (SPF).
 */
void build_sieve() {
    spf.resize(MAX_VAL);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (spf[i] == i) {
            for (long long j = 1LL * i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) {
                    spf[j] = (int)i;
                }
            }
        }
    }
}

/**
 * @brief Gets all unique prime factors of x.
 */
void get_prime_factors(int x, set<int>& factors) {
    while (x > 1) {
        factors.insert(spf[x]);
        x /= spf[x];
    }
}

/**
 * @brief Helper to update the two smallest costs.
 */
void update_min_costs(pair<long long, long long>& costs, long long new_cost) {
    if (new_cost < costs.first) {
        costs.second = costs.first;
        costs.first = new_cost;
    } else if (new_cost < costs.second) {
        costs.second = new_cost;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    // Read and ignore b
    for (int i = 0; i < n; ++i) { int b; cin >> b; }

    // Set of primes that we touch in this test case
    set<int> primes_to_clean;

    // This is the main O(n * log M) loop
    for (int x : a) {
        // Get all relevant primes for this x
        set<int> temp_factors;
        get_prime_factors(x, temp_factors);
        get_prime_factors(x + 1, temp_factors);

        // For each relevant prime, calculate this x's cost
        // and update the global min costs
        for (int p : temp_factors) {
            long long cost = (p - (x % p)) % p;
            update_min_costs(min_prime_costs[p], cost);
            primes_to_clean.insert(p);
        }
    }
    
    // Default answer is n (max possible cost)
    long long min_total_cost = n; 

    // Find the min cost, iterating *only* over primes we've seen
    for (int p : primes_to_clean) {
        min_total_cost = min(min_total_cost, 
                             min_prime_costs[p].first + min_prime_costs[p].second);
    }

    // !! CRITICAL !!
    // Clean up the global array for the next test case
    for (int p : primes_to_clean) {
        min_prime_costs[p] = {INF, INF};
    }

    cout << min_total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Build the sieve once
    build_sieve();

    // Initialize the global cost array once
    min_prime_costs.assign(MAX_VAL, {INF, INF});

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}