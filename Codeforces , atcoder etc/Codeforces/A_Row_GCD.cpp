#include <bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    if (n == 1) {
        for (int i = 0; i < m; ++i) {
            cout << a[0] + b[i] << (i == m - 1 ? "" : " ");
        }
        cout << "\n";
        return 0;
    }

    sort(a.begin(), a.end());

    long long g = 0;
    for (int i = 1; i < n; ++i) {
        g = gcd(g, a[i] - a[0]);
    }

    for (int i = 0; i < m; ++i) {
        cout << gcd(a[0] + b[i], g) << (i == m - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}