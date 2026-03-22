#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Calculates the number of cuts required to reduce a dimension of size k to 1
 * assuming the opponent always positions the monster optimally (in the center).
 * This is equivalent to ceil(log2(k)).
 */
int get_steps(int k) {
    if (k <= 1) return 0;
    int steps = 0;
    long long val = 1;
    while (val < k) {
        val *= 2;
        steps++;
    }
    return steps;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    // Option 1: Mouf cuts horizontally first.
    // He keeps the strip containing row 'a' that is smallest.
    // The height becomes min(distance to top, distance to bottom).
    int n_after_row_cut = min(a, n - a + 1);
    int cost_row_first = 1 + get_steps(n_after_row_cut) + get_steps(m);

    // Option 2: Mouf cuts vertically first.
    // He keeps the strip containing col 'b' that is smallest.
    int m_after_col_cut = min(b, m - b + 1);
    int cost_col_first = 1 + get_steps(n) + get_steps(m_after_col_cut);

    // Mouf plays optimally to minimize the turns.
    cout << min(cost_row_first, cost_col_first) << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}