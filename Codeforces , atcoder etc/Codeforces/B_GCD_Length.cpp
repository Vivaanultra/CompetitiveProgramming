#include <bits/stdc++.h>

using namespace std;

long long power(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; ++i) {
        res *= base;
    }
    return res;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    long long g = power(10, c - 1);

    long long x = g;
    while (to_string(x).length() < a) {
        x *= 2;
    }

    long long y = g;
    while (to_string(y).length() < b) {
        y *= 3;
    }

    cout << x << " " << y << endl;
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