#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Initialize the boundaries of the "safe zone" to the maximum possible area.
    int min_x = -100000;
    int max_x = 100000;
    int min_y = -100000;
    int max_y = 100000;

    for (int i = 0; i < n; ++i) {
        int x, y, f1, f2, f3, f4;
        cin >> x >> y >> f1 >> f2 >> f3 >> f4;

        // For each disabled move, shrink the corresponding boundary.
        if (f1 == 0) { // Cannot move left
            min_x = max(min_x, x);
        }
        if (f2 == 0) { // Cannot move up
            max_y = min(max_y, y);
        }
        if (f3 == 0) { // Cannot move right
            max_x = min(max_x, x);
        }
        if (f4 == 0) { // Cannot move down
            min_y = max(min_y, y);
        }
    }

    // Check if the final "safe zone" is a valid rectangle.
    if (min_x <= max_x && min_y <= max_y) {
        // If it's valid, any point inside is a solution. We can print a corner.
        cout << 1 << " " << min_x << " " << min_y << "\n";
    } else {
        // If the rectangle is invalid (e.g., min_x > max_x), no solution exists.
        cout << 0 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}