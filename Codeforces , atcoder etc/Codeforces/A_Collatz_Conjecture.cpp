#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k, x;
    cin >> k >> x;

    // Calculate x * 2^k using a bit shift for efficiency.
    // This finds a valid starting number by reversing the 'x = x/2' operation k times.
    long long initial_x = x * (1LL << k);

    cout << initial_x << "\n";
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