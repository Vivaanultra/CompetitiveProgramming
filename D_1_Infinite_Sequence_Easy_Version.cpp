#include <bits/stdc++.h>
using namespace std;

// Global variables to store problem data for recursion
int n;
vector<int> a;        // Original sequence a
vector<int> P;        // Prefix XORs of a: P[i] = a[1] ^ ... ^ a[i]
vector<long long> SP; // Prefix sums of P: SP[i] = P[1] + ... + P[i]
vector<long long> Sa; // Prefix sums of a: Sa[i] = a[1] + ... + a[i]
int C;                // The stable constant value for P at odd indices > n

// Function to get the value of P at any index k
int get_val_P(long long k) {
    if (k <= n) return P[k];
    if (k % 2 != 0) return C; // Odd indices > n are constant C
    // Even indices: P[2k] = C ^ P[k]
    return C ^ get_val_P(k / 2);
}

// Function to calculate sum of P from index 1 to k
long long get_sum_P(long long k) {
    if (k <= 0) return 0;
    if (k <= n) return SP[k];

    // Base contribution from precomputed part
    long long res = SP[n];

    // Count odd indices in range (n, k]
    // Range of odds: n+1 (or n+2) ... to largest odd <= k
    long long odd_count = (k + 1) / 2 - (n + 1) / 2;
    if (C == 1) {
        res += odd_count;
    }

    // Handle even indices in range (n, k]
    // Evens are 2*j where j ranges from (n/2 + 1) to (k/2)
    long long l_idx = n / 2 + 1;
    long long r_idx = k / 2;

    if (l_idx <= r_idx) {
        long long count_even = r_idx - l_idx + 1;
        long long recursive_sum = get_sum_P(r_idx) - get_sum_P(l_idx - 1);

        if (C == 0) {
            // If C is 0, P[2j] = 0 ^ P[j] = P[j]
            res += recursive_sum;
        } else {
            // If C is 1, P[2j] = 1 ^ P[j] = 1 - P[j]
            // Sum is count_even - sum(P[j])
            res += (count_even - recursive_sum);
        }
    }

    return res;
}

// Function to calculate sum of sequence 'a' from 1 to k
long long query(long long k) {
    if (k <= 0) return 0;
    if (k <= n) return Sa[k];

    // Sum up to n is precomputed
    long long total = Sa[n];

    // We need sum of a[i] for i in [n+1, k]
    // a[i] = P[floor(i/2)]
    // Map range [n+1, k] to indices of P
    long long L = n + 1;
    long long R = k;

    long long p_idx_start = L / 2;
    long long p_idx_end = R / 2;

    // Calculate sum of P in range [p_idx_start, p_idx_end]
    long long sum_P_range = get_sum_P(p_idx_end) - get_sum_P(p_idx_start - 1);

    // Each P index essentially contributes twice to 'a' (once for 2j, once for 2j+1)
    total += 2 * sum_P_range;

    // Correction for the start boundary
    // If L is odd (2j+1), the range starts at 2j+1. 
    // The block for P[j] covers 2j and 2j+1. We included P[j]*2, but 2j is not in range.
    // So subtract P[j] once.
    if (L % 2 != 0) {
        total -= get_val_P(p_idx_start);
    }

    // Correction for the end boundary
    // If R is even (2j), the range ends at 2j.
    // The block for P[j] covers 2j and 2j+1. We included P[j]*2, but 2j+1 is not in range.
    // So subtract P[j] once.
    if (R % 2 == 0) {
        total -= get_val_P(p_idx_end);
    }

    return total;
}

void solve() {
    long long l, r;
    cin >> n >> l >> r;
    
    a.assign(n + 1, 0);
    P.assign(n + 1, 0);
    SP.assign(n + 1, 0);
    Sa.assign(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        Sa[i] = Sa[i - 1] + a[i];
        P[i] = P[i - 1] ^ a[i];
        SP[i] = SP[i - 1] + P[i];
    }
    
    // Determine the constant C for odd indices > n
    if (n % 2 != 0) {
        // If n is odd, the next index n+1 is even, n+2 is odd.
        // Actually, logic derived: P[2k+1] = C.
        // If n is odd, P[n] is an odd index. Does it equal C?
        // Not necessarily, the stability starts for 2k > n.
        // Let's compute C using the first valid odd index > n.
        // Index is n + (something).
        // Let's rely on formula: P[n+1] = P[n] ^ a[n+1] = P[n] ^ P[(n+1)/2]
        // If n+1 is odd (n even): C = P[n+1]
        // If n+1 is even (n odd): C = P[n+2] = P[n+1] ^ P[(n+2)/2]
        
        // Easier logic:
        // C is the value of P at any odd index > n.
        // Let's compute P[n+1] and P[n+2] if needed.
        int val_n_plus_1 = P[n] ^ P[(n + 1) / 2];
        C = val_n_plus_1 ^ P[(n + 2) / 2]; // n+2 is odd, so this is C
    } else {
        // n is even, so n+1 is odd.
        C = P[n] ^ P[(n + 1) / 2];
    }
    
    cout << query(r) - query(l - 1) << endl;
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