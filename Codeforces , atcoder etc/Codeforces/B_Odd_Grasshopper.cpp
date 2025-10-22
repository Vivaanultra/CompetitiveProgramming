#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x0, n;
    cin >> x0 >> n;

    // Find how many jumps are in the final, incomplete cycle.
    long long rem = n % 4;
    
    // Determine the first jump number of this final cycle.
    long long start_jump = n - rem + 1;

    // Start at the initial position, as all full 4-jump cycles cancel out.
    long long final_pos = x0;

    // Simulate only the leftover jumps.
    for (long long i = start_jump; i <= n; ++i) {
        if (final_pos % 2 == 0) { // Even position, jump left
            final_pos -= i;
        } else { // Odd position, jump right
            final_pos += i;
        }
    }

    cout << final_pos << endl;
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