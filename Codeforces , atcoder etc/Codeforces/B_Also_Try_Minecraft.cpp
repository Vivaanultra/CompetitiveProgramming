#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O is a good practice in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length, quests;
    cin >> length >> quests;

    vector<int> heights(length);
    for (int i = 0; i < length; i++) {
        cin >> heights[i];
    }

    // --- Prefix sums for forward traversal (left to right) ---
    // Use long long for damage to prevent overflow
    vector<long long> forward_damage(length, 0);
    for (int i = 1; i < length; i++) {
        forward_damage[i] = forward_damage[i - 1];
        if (heights[i] < heights[i - 1]) {
            // Add damage if moving down
            forward_damage[i] += (long long)heights[i - 1] - heights[i];
        }
    }

    // --- Prefix sums for backward traversal (right to left) ---
    // Use long long for damage to prevent overflow
    vector<long long> backward_damage(length, 0);
    for (int i = length - 2; i >= 0; i--) {
        backward_damage[i] = backward_damage[i + 1];
        if (heights[i] < heights[i + 1]) {
            // Add damage if moving down (from right to left)
            backward_damage[i] += (long long)heights[i + 1] - heights[i];
        }
    }

    while (quests--) {
        int start, end;
        cin >> start >> end;
        
        // Adjust to 0-based indexing
        start--; 
        end--;

        if (end > start) {
            // Forward case: damage is the difference in prefix sums
            cout << forward_damage[end] - forward_damage[start] << endl;
        } else {
            // Backward case: damage is the difference in backward prefix sums
            // Note: backward_damage[start] represents total damage from the end to `start`
            // and backward_damage[end] is total damage from the end to `end`.
            // The difference gives the damage for the segment from `start` to `end`.
            cout << backward_damage[end] - backward_damage[start] << endl;
        }
    }
    
    return 0;
}