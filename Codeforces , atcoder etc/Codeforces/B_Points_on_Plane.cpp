#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Using competitive programming practices as requested
#include <bits/stdc++.h>
using namespace std;

// Calculates the max number of non-adjacent chips for a given cost C
long long count_chips(long long C) {
    if (C < 0) return 0;
    
    // The number of placable chips depends on the parity of C
    if (C % 2 == 1) {
        // If C is odd, count(C) = (C+1)^2
        long long temp = C + 1;
        return temp * temp;
    } else {
        // If C is even, count(C) = 1 + 2*C*(C/2 + 1)
        return 1 + 2 * C * (C / 2 + 1);
    }
}

void solve() {
    long long n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    // Binary search for the minimum cost C
    long long low = 0;
    long long high = 2000000000; // A safe upper bound for C
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (count_chips(mid) >= n) {
            // If cost 'mid' can accommodate n chips, it's a possible answer.
            // Try to find an even smaller cost.
            ans = mid;
            high = mid - 1;
        } else {
            // If cost 'mid' is not enough, we need a higher cost.
            low = mid + 1;
        }
    }

    cout << ans << endl;
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