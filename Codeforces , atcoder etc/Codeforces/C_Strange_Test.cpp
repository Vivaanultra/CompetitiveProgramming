#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    int min_ops = b - a;

    // Path 2: Increment 'a' only, then OR
    for (int i = 0; i < min_ops; ++i) {
        int new_a = a + i;
        int current_ops = i + 1 + ((new_a | b) - b);
        min_ops = min(min_ops, current_ops);
    }

    // Path 3: Increment 'b' only, then OR
    for (int j = 0; j < min_ops; ++j) {
        int new_b = b + j;
        // Check if a is already a submask of new_b
        if ((a | new_b) == new_b) {
            min_ops = min(min_ops, j + 1);
        } else {
            int current_ops = j + 1 + ((a | new_b) - new_b);
            min_ops = min(min_ops, current_ops);
        }
    }
    
    cout << min_ops << "\n";
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