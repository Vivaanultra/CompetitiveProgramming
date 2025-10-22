#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1000001;
vector<int> spf(MAXA);

void sieve() {
    for (int i = 0; i < MAXA; ++i) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXA; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map<int, int> prime_counts;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        while (a > 1) {
            prime_counts[spf[a]]++;
            a /= spf[a];
        }
    }

    bool possible = true;
    for (auto const& pair : prime_counts) {
        if (pair.second % n != 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
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