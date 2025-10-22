#include <bits/stdc++.h>

using namespace std;

int count_prime_factors(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    if (n > 1) {
        count++;
    }
    return count;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    if (k == 1) {
        if (a != b && (a % b == 0 || b % a == 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    int max_k = count_prime_factors(a) + count_prime_factors(b);
    if (k <= max_k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}