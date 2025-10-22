#include <bits/stdc++.h>

using namespace std;

const int SIEVE_LIMIT = 32000;
vector<int> primes;
vector<bool> is_prime_sieve;

void sieve() {
    is_prime_sieve.assign(SIEVE_LIMIT + 1, true);
    is_prime_sieve[0] = is_prime_sieve[1] = false;
    for (int p = 2; p * p <= SIEVE_LIMIT; ++p) {
        if (is_prime_sieve[p]) {
            for (int i = p * p; i <= SIEVE_LIMIT; i += p)
                is_prime_sieve[i] = false;
        }
    }
    for (int p = 2; p <= SIEVE_LIMIT; ++p) {
        if (is_prime_sieve[p]) {
            primes.push_back(p);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> seen_primes;
    bool found_pair = false;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int val : a) {
        int temp = val;
        for (int p : primes) {
            if ((long long)p * p > temp) {
                break;
            }
            if (temp % p == 0) {
                if (seen_primes.count(p)) {
                    found_pair = true;
                    break;
                }
                seen_primes.insert(p);
                while (temp % p == 0) {
                    temp /= p;
                }
            }
        }
        if (found_pair) {
            break;
        }
        if (temp > 1) {
            if (seen_primes.count(temp)) {
                found_pair = true;
            } else {
                seen_primes.insert(temp);
            }
        }
        if (found_pair) {
            break;
        }
    }

    if (found_pair) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}