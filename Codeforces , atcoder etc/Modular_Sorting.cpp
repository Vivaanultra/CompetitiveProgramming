#include <bits/stdc++.h>

using namespace std;

// Function to compute the greatest common divisor
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Function to find all divisors of a number
vector<int> get_divisors(int m) {
    vector<int> divisors;
    for (int i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            divisors.push_back(i);
            if (i * i != m) {
                divisors.push_back(m / i);
            }
        }
    }
    return divisors;
}

void solve() {
    int n;
    long long m;
    int q;
    cin >> n >> m >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Pre-calculate bad pair counts for every divisor of m.
    // A "bad pair" (i-1, i) for a divisor d is one where a[i]%d < a[i-1]%d.
    vector<int> divisors = get_divisors(m);
    map<int, long long> bad_pair_counts;

    // Initialize counts for each divisor.
    for (int d : divisors) {
        long long current_bad_pairs = 0;
        for (int i = 1; i < n; ++i) {
            if ((a[i] % d) < (a[i - 1] % d)) {
                current_bad_pairs++;
            }
        }
        bad_pair_counts[d] = current_bad_pairs;
    }

    // Process queries
    for (int k = 0; k < q; ++k) {
        int type;
        cin >> type;
        if (type == 1) {
            // Update query: a[i] := x
            int i;
            long long x;
            cin >> i >> x;
            --i; // Using 0-based indexing

            long long old_val = a[i];

            // An update to a[i] affects pairs (i-1, i) and (i, i+1).
            // We update the bad pair counts for all divisors of m.
            for (int d : divisors) {
                // Update for pair (i-1, i)
                if (i > 0) {
                    bad_pair_counts[d] -= ((old_val % d) < (a[i - 1] % d));
                    bad_pair_counts[d] += ((x % d) < (a[i - 1] % d));
                }
                // Update for pair (i, i+1)
                if (i < n - 1) {
                    bad_pair_counts[d] -= ((a[i + 1] % d) < (old_val % d));
                    bad_pair_counts[d] += ((a[i + 1] % d) < (x % d));
                }
            }
            a[i] = x;

        } else { // type == 2
            // Check query
            long long val_k;
            cin >> val_k;
            long long g = gcd(val_k, m);

            long long bad_pairs = bad_pair_counts.at(g);
            long long last_rem = a[n - 1] % g;
            
            // Check if the final element of the greedily constructed sequence is less than m
            if (bad_pairs * g + last_rem < m) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
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