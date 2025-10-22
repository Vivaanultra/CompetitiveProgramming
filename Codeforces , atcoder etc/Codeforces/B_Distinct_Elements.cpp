#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> a(n);
    vector<int> val_map(n + 1); // Maps index p to its assigned value a_p
    int next_new_val = 1;
    long long prev_b = 0;

    for (int i = 0; i < n; ++i) {
        long long current_b = b[i];
        long long delta = current_b - prev_b;
        
        // p = (i+1) - delta, because we are using 1-based logic for i
        int p = (i + 1) - delta;

        if (p == 0) {
            // This is a new value
            a[i] = next_new_val;
            val_map[i + 1] = next_new_val; // Store the value for this index
            next_new_val++;
        } else {
            // Value is same as a_p
            int val_at_p = val_map[p];
            a[i] = val_at_p;
            val_map[i + 1] = val_at_p; // Store the value for this index
        }
        
        prev_b = current_b;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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