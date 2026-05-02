#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

// DP State: [bit][count][carry][val_sat]
// bit: 0 to 62
// count: number of set bits added so far (up to k)
// carry: carry to the next bit (0 or 1)
// val_sat: value of D constructed so far, saturated at k+1 (to track D >= k)
int dp[63][33][2][34];
const int INF = 1e9;

int countSetBits(long long n) {
    return __builtin_popcountll(n);
}

void solve() {
    long long n;
    int k;
    cin >> n >> k;

    // Case 1: Large k
    // We can always reduce n to a power of 2 (popcount 1).
    // n < 2^30, so 30 moves are enough to clear all bits via carries.
    if (k >= 31) {
        cout << countSetBits(n) + k - 1 << "\n";
        return;
    }

    // Case 2: Small k (DP)
    // Initialize DP table
    // range: bit 0..62, count 0..k, carry 0..1, val 0..k+1
    for (int i = 0; i <= 62; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j][0][0] = INF; // We only need to init the entries we might reach
            // To be safe and simple, we can use memset if dimensions are fixed,
            // but loop init is fine given small size.
            for (int v = 0; v <= k + 1; ++v) {
                dp[i][j][0][v] = INF;
                dp[i][j][1][v] = INF;
            }
        }
    }

    // Base case: bit 0, count 0, carry 0, val 0
    dp[0][0][0][0] = 0;

    for (int i = 0; i < 62; ++i) {
        int bit_n = (n >> i) & 1;
        
        for (int j = 0; j <= k; ++j) {
            for (int c = 0; c <= 1; ++c) {
                for (int v = 0; v <= k + 1; ++v) {
                    if (dp[i][j][c][v] == INF) continue;

                    // Try adding 0 or 1 at this bit position for D
                    for (int bit_d = 0; bit_d <= 1; ++bit_d) {
                        // Calculate new count of used operations
                        int next_j = j + bit_d;
                        if (next_j > k) continue;

                        // Calculate sum at this position
                        int sum = bit_n + bit_d + c;
                        int next_c = sum / 2;
                        int res_bit = sum % 2; // This is the bit of n_final

                        // Calculate new value of D (saturated at k+1)
                        // We strictly need D >= k eventually.
                        // value += bit_d * 2^i
                        // Since k is small (<=31), 2^i grows fast. 
                        // If i >= 5, 2^i >= 32 > k.
                        int next_v = v;
                        if (bit_d) {
                            if (i >= 5) {
                                next_v = k + 1;
                            } else {
                                next_v += (1 << i);
                                if (next_v > k + 1) next_v = k + 1;
                            }
                        }

                        // Transition
                        // We add 'res_bit' to the popcount of n_final
                        int current_pop = dp[i][j][c][v];
                        if (current_pop + res_bit < dp[i + 1][next_j][next_c][next_v]) {
                            dp[i + 1][next_j][next_c][next_v] = current_pop + res_bit;
                        }
                    }
                }
            }
        }
    }

    // Find minimum popcount(n_final)
    int min_final_pop = INF;
    
    // We check state at bit 62.
    // Carry must be 0 (or we just include the carry as a final MSB, which counts as 1)
    // Actually bit 62 is well beyond n (approx 10^9), so carry usually 0.
    // If carry is 1, it adds a bit at pos 62.
    
    for (int j = 0; j <= k; ++j) {
        for (int c = 0; c <= 1; ++c) {
            for (int v = 0; v <= k + 1; ++v) {
                if (dp[62][j][c][v] == INF) continue;
                
                // We strictly need accumulated D >= k
                if (v < k) continue;

                int final_pop = dp[62][j][c][v];
                if (c == 1) final_pop++; // Carry out becomes a set bit

                if (final_pop < min_final_pop) {
                    min_final_pop = final_pop;
                }
            }
        }
    }

    cout << countSetBits(n) - min_final_pop + k << "\n";
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