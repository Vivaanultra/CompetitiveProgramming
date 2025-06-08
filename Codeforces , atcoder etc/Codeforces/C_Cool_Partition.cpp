#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Single element or empty array is 1 segment
    if (n <= 1) {
        cout << 1 << "\n";
        return;
    }
    
    // Start with 1 segment
    int segments = 1;
    set<int> s_right; // Unique elements in current rightmost segment
    
    // Process from right to left
    for (int i = n - 1; i >= 1; i--) {
        s_right.insert(a[i]);
        // If element to the left is in right segment, we can make a cut
        if (s_right.count(a[i - 1])) {
            segments++;
            s_right.clear();
        }
    }
    
    cout << segments << "\n";
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