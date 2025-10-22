#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << n << "\n";
        return;
    }

    long long operations = 0;
    while (n > 0) {
        operations += n % k;
        n /= k;
    }

    cout << operations << "\n";
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