#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long k;
    cin >> k;

    // Step 1: Find the side length 's' of the square shell containing k.
    long long s = ceil(sqrt(k));

    // Step 2: Calculate the corner value, which is the turning point of the "L" shape.
    // This value is always found at coordinates (s, s).
    long long corner_val = s * s - s + 1;

    long long r, c;

    // Step 3: Compare k to the corner value to determine its position.
    if (k > corner_val) {
        // Case 1: k is on the horizontal part of the "L" (after the corner).
        // The row is fixed at s.
        r = s;
        // The column decreases as k increases from the corner.
        c = s * s - k + 1;
    } else {
        // Case 2: k is on the vertical part of the "L" (before or at the corner).
        // The column is fixed at s.
        c = s;
        // The row is determined by how far k is from the end of the previous shell.
        long long prev_square = (s - 1) * (s - 1);
        r = k - prev_square;
    }

    cout << r << " " << c << endl;
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