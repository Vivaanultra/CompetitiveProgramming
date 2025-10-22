#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_SIZE = 200005;

long long fact[MAX_SIZE];
long long invFact[MAX_SIZE];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_SIZE; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX_SIZE - 1] = modInverse(fact[MAX_SIZE - 1]);
    for (int i = MAX_SIZE - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr_mod_p(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a == 0) {
        cout << 0 << endl;
        return;
    }
    if (b == 0) {
        cout << 1 << endl;
        return;
    }

    long long p_L = (long long)a * modInverse(a + b) % MOD;
    long long p_D = (long long)b * modInverse(a + b) % MOD;

    long long summation_term = 0;
    long long p_D_pow_i = 1;

    for (int i = 0; i < n; ++i) {
        long long combinations = nCr_mod_p(n + i - 1, i);
        long long term = (combinations * p_D_pow_i) % MOD;
        summation_term = (summation_term + term) % MOD;
        p_D_pow_i = (p_D_pow_i * p_D) % MOD;
    }

    long long p_L_pow_n = power(p_L, n);
    long long ans = (p_L_pow_n * summation_term) % MOD;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorials();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}