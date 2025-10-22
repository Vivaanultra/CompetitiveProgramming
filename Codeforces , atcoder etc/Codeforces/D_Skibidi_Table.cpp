#include<bits/stdc++.h>
using namespace std;
// Using long long for numbers and coordinates to avoid overflow
using int64 = long long;

// Recursive function to find the number at (x, y)
int64 get_val(int n, int64 x, int64 y) {
    if (n == 0) {
        return 1;
    }
    int64 half = 1LL << (n - 1);
    int64 quad_size = 1LL << (2 * n - 2);

    if (x <= half && y <= half) { // Top-Left
        return get_val(n - 1, x, y);
    }
    if (x > half && y > half) { // Bottom-Right
        return quad_size + get_val(n - 1, x - half, y - half);
    }
    if (x > half && y <= half) { // Bottom-Left
        return 2 * quad_size + get_val(n - 1, x - half, y);
    }
    // Top-Right
    return 3 * quad_size + get_val(n - 1, x, y - half);
}

// Recursive function to find coordinates of a number d
pair<int64, int64> get_coords(int n, int64 d) {
    if (n == 0) {
        return {1, 1};
    }
    int64 half = 1LL << (n - 1);
    int64 quad_size = 1LL << (2 * n - 2);

    if (d <= quad_size) { // Top-Left
        return get_coords(n - 1, d);
    }
    if (d <= 2 * quad_size) { // Bottom-Right
        auto p = get_coords(n - 1, d - quad_size);
        return {p.first + half, p.second + half};
    }
    if (d <= 3 * quad_size) { // Bottom-Left
        auto p = get_coords(n - 1, d - 2 * quad_size);
        return {p.first + half, p.second};
    }
    // Top-Right
    auto p = get_coords(n - 1, d - 3 * quad_size);
    return {p.first, p.second + half};
}


void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; ++i) {
        string type;
        cin >> type;
        if (type == "->") {
            int64 x, y;
            cin >> x >> y;
            cout << get_val(n, x, y) << "\n";
        } else { // "<-"
            int64 d;
            cin >> d;
            auto p = get_coords(n, d);
            cout << p.first << " " << p.second << "\n";
        }
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