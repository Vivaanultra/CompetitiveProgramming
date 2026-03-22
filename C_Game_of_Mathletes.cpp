#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    // Frequency array to count occurrences of each number
    // x_i is at most n, so size n+1 is sufficient.
    vector<int> cnt(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // We only care about x if it's less than k 
        // (since x >= k cannot be part of a sum = k with positive integers)
        if (x < k) {
            cnt[x]++;
        }
    }
    
    int score = 0;
    
    // Iterate through half of k to find pairs
    for (int i = 1; i <= k / 2; i++) {
        int complement = k - i;
        
        // Ensure complement is within valid range [1, n]
        if (complement > n) continue;
        
        if (i == complement) {
            // If the number is exactly k/2, we need two of them to make a pair
            score += cnt[i] / 2;
        } else {
            // Otherwise, we take the minimum of the count of i and its complement
            score += min(cnt[i], cnt[complement]);
        }
    }
    
    cout << score << "\n";
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