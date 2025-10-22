#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_count = 0;
    int last_x_idx = -1;      // Index of the most recent X
    int last_y_idx = -1;      // Index of the most recent Y
    int last_bad_idx = -1;    // Index of the most recent invalid number

    for (int right = 0; right < n; ++right) {
        // Update the last seen indices based on the current element
        if (a[right] == x) {
            last_x_idx = right;
        }
        if (a[right] == y) {
            last_y_idx = right;
        }
        if (a[right] < y || a[right] > x) {
            // This element breaks all current valid windows.
            // Any new valid window must start after this point.
            last_bad_idx = right;
        }

        // Determine the boundary for valid left pointers.
        // A valid left pointer must be after the last bad element,
        // but at or before the last seen X and Y to include them.
        int valid_start_boundary = min(last_x_idx, last_y_idx);

        // The number of valid subarrays ending at 'right' is the size of the valid range for 'left'.
        if (valid_start_boundary > last_bad_idx) {
            total_count += (long long)(valid_start_boundary - last_bad_idx);
        }
    }

    cout << total_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(); // This problem has only one test case per run
    return 0;
}