#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    long long total_pairs = 0;
    long long current_p = 1; // Represents k^n, starting at k^0 = 1

    while (true) {

        
        long long min_x_from_y = (l2 + current_p - 1) / current_p;
        long long max_x_from_y = r2 / current_p;

        // Intersection with [l1, r1]
        long long start = max(l1, min_x_from_y);
        long long end = min(r1, max_x_from_y);

        if (start <= end) {
            total_pairs += (end - start + 1);
        }

        if (current_p > r2 / k) {
            break;
        }

        current_p *= k;
    }

    cout << total_pairs << "\n";
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