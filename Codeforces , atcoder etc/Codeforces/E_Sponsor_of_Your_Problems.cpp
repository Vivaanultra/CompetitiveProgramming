#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Solves a single test case
void solve() {
    string l, r;
    cin >> l >> r;
    int n = l.length();

    // Find the first position k where l and r differ
    int k = 0;
    while (k < n && l[k] == r[k]) {
        k++;
    }

    // If l and r are the same, x must be l.
    // f(l,l) + f(l,l) = n + n = 2n
    if (k == n) {
        cout << 2 * n << endl;
        return;
    }

    // Case 1: Gap between differing digits is larger than 1.
    // We can pick x_k between l_k and r_k.
    // This makes l < x < r, and we can choose remaining digits of x freely.
    // To minimize cost, we choose x_i != l_i and x_i != r_i for i > k.
    // Cost from prefix 0..k-1 is 2*k.
    // Cost from suffix k..n-1 can be made 0.
    if (r[k] - l[k] > 1) {
        cout << 2LL * k << endl;
        return;
    }

    // Case 2: Gap is exactly 1 (e.g., l_k=4, r_k=5).
    // We must choose x_k to be either l_k or r_k.
    // This adds a cost of 1 at position k. Base cost = 2*k + 1.
    long long base_cost = 2LL * k + 1;

    // DP to find minimum additional cost from suffix k+1...n-1
    
    // cost_l: min cost for suffix assuming we chose x_k = l_k
    long long cost_l = 0;
    for (int i = n - 1; i > k; --i) {
        // Option 1: Stay tight with l (x_i = l_i)
        // Cost at i is 1 (for l_i==x_i) + (l_i==r_i).
        long long stay = 1 + (l[i] == r[i]) + cost_l;
        
        // Option 2: Break away from l (x_i > l_i)
        // Cost at i is (x_i==r_i). After this, we are free, so future cost is 0.
        // We want to find min cost for x_i > l_i.
        long long breakaway;
        if (l[i] == '9') breakaway = 20; // Cannot break away upwards
        else if (l[i] == '8') breakaway = (r[i] == '9' ? 1 : 0);
        else breakaway = 0; // Can always pick x_i > l_i and x_i != r_i
        
        cost_l = min(stay, breakaway);
    }

    // cost_r: min cost for suffix assuming we chose x_k = r_k
    long long cost_r = 0;
    for (int i = n - 1; i > k; --i) {
        // Option 1: Stay tight with r (x_i = r_i)
        long long stay = 1 + (l[i] == r[i]) + cost_r;
        
        // Option 2: Break away from r (x_i < r_i)
        long long breakaway;
        if (r[i] == '0') breakaway = 20; // Cannot break away downwards
        else if (r[i] == '1') breakaway = (l[i] == '0' ? 1 : 0);
        else breakaway = 0; // Can always pick x_i < r_i and x_i != l_i
        
        cost_r = min(stay, breakaway);
    }

    cout << base_cost + min(cost_l, cost_r) << endl;
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