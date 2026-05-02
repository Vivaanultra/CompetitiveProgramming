#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    long long n, x, y;
    if (!(cin >> n >> x >> y)) return;
    string s;
    cin >> s;

    long long cnt8 = 0;
    for (char c : s) {
        if (c == '8') {
            cnt8++;
        }
    }
    long long cnt4 = n - cnt8;

    // Constraint 1: Box bounds
    // Both operations increase the bounding box radius by 1.
    long long max_coord = n;

    // Constraint 2: Diagonal bounds (Manhattan distance)
    // '4' increases Manhattan radius by 1.
    // '8' increases Manhattan radius by 2.
    long long max_manhattan = cnt4 + 2 * cnt8;

    long long abs_x = abs(x);
    long long abs_y = abs(y);

    if (abs_x <= max_coord && abs_y <= max_coord && (abs_x + abs_y <= max_manhattan)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
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