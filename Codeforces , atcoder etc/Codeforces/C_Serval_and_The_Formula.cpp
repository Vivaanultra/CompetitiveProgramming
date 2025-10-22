#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;

    // Handle the impossible case where x and y are the same.
    // x+k will always equal y+k, so their bitwise AND can only be 0
    // if x+k=0, which requires a negative k.
    if (x == y) {
        cout << -1 << endl;
        return;
    }

    // The constructive approach: force one of the resulting numbers 
    // to become a large power of 2, P, which has only one bit set.
    // Let's choose P = 2^48, which is safely larger than x and y.
    long long P = 1LL << 48;

    // To make the larger of the two numbers (x or y) become P after adding k,
    // we can calculate the required k.
    long long k = P - max(x, y);
    
    // This works because if we assume x > y, then:
    // x + k = x + (P - x) = P
    // y + k = y + (P - x) = P - (x-y)
    // The bitwise AND of P and (P - a positive number) is always 0.

    cout << k << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}