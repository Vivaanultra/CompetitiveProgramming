#include <iostream>
#include <cmath>
#include <algorithm>

void solve() {
    int xa, ya, xb, yb, xf, yf;
    std::cin >> xa >> ya >> xb >> yb >> xf >> yf;

    int ans = std::abs(xa - xb) + std::abs(ya - yb);

    // Case 1: A, B, and F are in the same row
    if (ya == yb && yb == yf) {
        // Check if F is between A and B
        if ((xf > xa && xf < xb) || (xf > xb && xf < xa)) {
            ans += 2;
        }
    }
    // Case 2: A, B, and F are in the same column
    else if (xa == xb && xb == xf) {
        // Check if F is between A and B
        if ((yf > ya && yf < yb) || (yf > yb && yf < ya)) {
            ans += 2;
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        // There is an empty line before each test case in the input
        // but it doesn't affect standard integer input reading with std::cin.
        solve();
    }
    return 0;
}