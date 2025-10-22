#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    bool possible = false;

    // Case 1: All rectangles have length l1, forming a square of side l1.
    if (l1 == l2 && l1 == l3 && l1 == b1 + b2 + b3) {
        possible = true;
    }

    // Case 2: L-shape fill, square of side l1.
    if (!possible && l1 == l2 + l3 && b2 == b3 && l1 == b1 + b2) {
        possible = true;
    }

    // Case 3: All rectangles have breadth b1, forming a square of side b1.
    if (!possible && b1 == b2 && b1 == b3 && b1 == l1 + l2 + l3) {
        possible = true;
    }

    // Case 4: L-shape fill, square of side b1.
    if (!possible && b1 == b2 + b3 && l2 == l3 && b1 == l1 + l2) {
        possible = true;
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}