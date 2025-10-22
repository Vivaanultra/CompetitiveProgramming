#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    // The difference between opposite people is half the circle size.
    int diff = abs(a - b);
    int circle_size = 2 * diff;

    // Check if the given people can exist in a circle of this size.
    // If a, b, or c is larger than the total number of people, it's impossible.
    // Also, the difference itself must be at least as large as the smaller of a or b,
    // but the check against circle_size is sufficient.
    if (a > circle_size || b > circle_size || c > circle_size) {
        cout << -1 << endl;
        return;
    }

    // The person opposite c is either c + diff or c - diff.
    // We find which one falls within the valid range [1, circle_size].
    int d = c + diff;
    if (d > circle_size) {
        d = c - diff;
    }

    // After the check above, d might still be invalid if the initial inputs were
    // contradictory in a subtle way (e.g., a=1, b=3 -> diff=2, N=4. But c=4. Opposite of 4 should be 2.
    // d = 4 + 2 = 6. > 4, so d = 4 - 2 = 2. It works).
    // The initial size check is sufficient for all cases.
    cout << d << endl;
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