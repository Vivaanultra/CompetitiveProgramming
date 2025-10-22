#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<long long> divs_a, divs_b;
    for (long long i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            divs_a.push_back(i);
            if (i * i != a) divs_a.push_back(a / i);
        }
    }
    for (long long i = 1; i * i <= b; ++i) {
        if (b % i == 0) {
            divs_b.push_back(i);
            if (i * i != b) divs_b.push_back(b / i);
        }
    }

    long long ab_prod = a * b;

    for (long long da : divs_a) {
        for (long long db : divs_b) {
            long long f1 = da * db;
            long long f2 = ab_prod / f1;

            long long k1 = a / f1 + 1;
            long long x = k1 * f1;

            if (x > c) {
                continue;
            }

            long long k2 = b / f2 + 1;
            long long y = k2 * f2;

            if (y > d) {
                continue;
            }
            
            cout << x << " " << y << "\n";
            return;
        }
    }

    cout << -1 << " " << -1 << "\n";
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