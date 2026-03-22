#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Souvlaki can choose the initial permutation. 
    // To minimize Kalamaki's impact, we assume Souvlaki picks the sorted order.
    sort(a.begin(), a.end());

    // Kalamaki plays on rounds 2, 4, 6... 
    // Round k affects indices k and k+1 (1-based).
    // In 0-based indexing, Kalamaki controls pairs (1,2), (3,4), (5,6)...
    // If a[i] != a[i+1] at these positions, Kalamaki can ensure the array is NOT sorted.
    // Souvlaki cannot fix the first element of the pair after Kalamaki moves.
    
    bool possible = true;
    for (int i = 1; i < n - 1; i += 2) {
        if (a[i] != a[i+1]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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