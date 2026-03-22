#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b >= a) {
        cout << b << endl;
        return;
    }

    if (c <= d) {
        cout << -1 << endl;
        return;
    }

    long long rem = a - b;
    long long gain = c - d;
    long long k = (rem + gain - 1) / gain;
    
    cout << b + k * c << endl;
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