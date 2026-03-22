#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int bit[MAXN]; // Fenwick Tree Array
int n;

// Standard Fenwick Update: Adds val to index idx
void add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

// Binary Lifting to find the smallest index with prefix sum == target_sum
// This works in O(log N)
int find_kth_person(int k) {
    int idx = 0;
    int current_sum = 0;
    
    // Iterate bits from highest to lowest (e.g., 1<<17 down to 1)
    // 1<<18 is roughly 260,000, enough for N=200,000
    for (int i = 1 << 18; i > 0; i >>= 1) {
        // Try jumping ahead by 'i' positions
        if (idx + i <= n && current_sum + bit[idx + i] < k) {
            idx += i;
            current_sum += bit[idx];
        }
    }
    // The answer is the next position
    return idx + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> n >> k;

    // 1. Initialize BIT: Everyone is present (value 1)
    // Just add 1 to every position
    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }

    int current_pos = 0; // Relative position (0-indexed)
    
    for (int remaining = n; remaining > 0; remaining--) {
        // 2. Calculate which person to remove next
        // The skipping wraps around the 'remaining' count
        current_pos = (current_pos + k) % remaining;
        
        // 3. Find the actual index of the (current_pos + 1)-th person
        int person_idx = find_kth_person(current_pos + 1);
        
        cout << person_idx << " ";
        
        // 4. Remove this person (update value by -1)
        add(person_idx, -1);
        
        // Note: current_pos stays the same numerically for the next iteration
        // because the list effectively shifts left at the deletion point.
    }
    
    cout << endl;
    return 0;
}