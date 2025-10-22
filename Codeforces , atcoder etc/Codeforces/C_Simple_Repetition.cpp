#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x;
        int k;
        cin >> x >> k;
        
        if (k == 1) {
            cout << (isPrime(x) ? "YES\n" : "NO\n");
            continue;
        }
        
        // k > 1
        if (x != 1) {
            cout << "NO\n";
            continue;
        }
        
        // x == 1, check repunit R_k = 111...1 (k times)
        long long rep = 0;
        for (int i = 0; i < k; ++i) rep = rep * 10 + 1;
        cout << (isPrime(rep) ? "YES\n" : "NO\n");
    }
    return 0;
}
