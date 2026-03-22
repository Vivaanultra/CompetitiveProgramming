#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // We use long long for current_min to ensure the multiplication 
    // 2 * current_min does not overflow, although with 10^9 constraint
    // standard int logic holds (2*10^9 fits in signed 32-bit int generally, 
    // but safety is preferred).
    long long current_min = b[0];
    bool possible = true;

    for (int i = 1; i < n; ++i) {
        // If the current target b[i] is strictly greater than the bottleneck
        if (b[i] > current_min) {
            // It must be strictly less than twice the bottleneck
            if (b[i] >= 2 * current_min) {
                possible = false;
                break;
            }
        }
        
        // Update the bottleneck for the next elements
        current_min = min(current_min, (long long)b[i]);
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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