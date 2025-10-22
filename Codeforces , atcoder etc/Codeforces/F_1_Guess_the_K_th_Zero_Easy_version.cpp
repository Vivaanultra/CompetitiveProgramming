#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    while (t--) {
        int k;
        cin >> k;

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Make the query
            cout << "? " << 1 << " " << mid << endl;
            
            int sum;
            cin >> sum;

            int zeros = mid - sum;

            if (zeros >= k) {
                // The k-th zero is in the range [1, mid]
                // This is a potential answer, so save it
                ans = mid;
                // Try to find a better (smaller) answer to the left
                high = mid - 1;
            } else {
                // Not enough zeros in [1, mid], so the k-th zero must be to the right
                low = mid + 1;
            }
        }
        
        // Output the final answer
        cout << "! " << ans << endl;
    }

    return 0;
}