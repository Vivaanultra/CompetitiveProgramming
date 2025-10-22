#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Using competitive programming practices
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int h1, h2, h3;

    // The core idea is to distribute n as evenly as possible and then
    // make minimal adjustments to satisfy the strict inequalities (h3 < h2 < h1)
    // while keeping h1 as small as possible. This leads to a simple
    // case analysis based on the remainder of n / 3.

    if (n % 3 == 0) {
        // Example n=6 -> 2,3,1. n/3=2. h2=2, h1=3, h3=1.
        h2 = n / 3;
        h1 = h2 + 1;
        h3 = h2 - 1;
    } else if (n % 3 == 1) {
        // Example n=7 -> 2,4,1. n/3=2. h2=2, h1=4, h3=1.
        // We give the extra block to h1, but then h1,h2 might be equal,
        // so we adjust again. This leads to h1 getting +2 total.
        h2 = n / 3;
        h1 = h2 + 2;
        h3 = h2 - 1;
    } else { // n % 3 == 2
        // Example n=8 -> 3,4,1. n/3=2. h2=3, h1=4, h3=1.
        // We give the two extra blocks to h1 and h2.
        h2 = n / 3 + 1;
        h1 = h2 + 1;
        h3 = n / 3; // or h2-2
    }
    
    // A final check. If the calculated h3 is 0, we need to adjust.
    // h3 must be at least 1. We take one from h2 and give it to h3.
    // This is only necessary if the above logic produces an h3 of 0,
    // which happens for small n if not careful. For n>=6, it should be fine.
    // A simple fix for all cases is to calculate a valid triplet and then adjust if h3=0.
    // But the above logic avoids h3=0 for n>=6. Let's make h3 calculation consistent.
    if (n % 3 == 2) {
       h3 = n / 3 - 1; // n/3 + 1 + n/3 + 2 + n/3 - 1 = 3*(n/3) + 2 = n
    }

    // A final final check. If h3 became 0 due to some calculation (it shouldn't for n>=6,
    // but as a safeguard), we fix it.
    if (h3 == 0) {
        h3 = 1;
        h2 -= 1;
    }


    cout << h2 << " " << h1 << " " << h3 << endl;
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