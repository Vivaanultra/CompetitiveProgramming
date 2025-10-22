#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 1000001;
long long counts[MAX_A + 1];
long long C[MAX_A + 2]; // C[k] = number of flavors with >= k bags
long long S[MAX_A + 2]; // S[k] = sum of bags for flavors with < k bags

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        counts[val]++;
        max_val = max(max_val, val);
    }
    
    // Pre-calculate C and S arrays
    // We can build C by iterating backwards
    for (int i = max_val; i >= 1; --i) {
        C[i] = C[i + 1] + counts[i];
    }

    // We can build S by iterating forwards
    for (int i = 1; i <= max_val; ++i) {
        S[i] = S[i - 1] + (long long)counts[i - 1] * (i - 1);
    }


    for (int i = 0; i < q; ++i) {
        long long b;
        cin >> b;

        // Impossible Case
        if (C[b] == 0) {
            cout << -1 << endl;
            continue;
        }

        // Calculate sum(min(A_i, b-1)) using pre-computed arrays
        // This is (sum of A_i where A_i < b) + (count of flavors with A_i >= b) * (b-1)
        long long sum_of_mins = S[b] + C[b] * (b - 1);

        // The answer is 1 + this sum
        cout << 1 + sum_of_mins << endl;
    }

    return 0;
}