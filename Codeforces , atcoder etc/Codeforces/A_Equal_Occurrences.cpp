#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
    }

    int max_len = 0;
    
    for (int c = 1; c <= n; ++c) {
        int distinct_elements_count = 0;
        for (auto const& pair : freq) {
            if (pair.second >= c) {
                distinct_elements_count++;
            }
        }
        max_len = max(max_len, distinct_elements_count * c);
    }
    
    cout << max_len << endl;
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