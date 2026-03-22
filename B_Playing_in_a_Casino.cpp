#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cols(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> cols[j][i];
            }
        }
        
        long long total_winnings = 0;
        for (int j = 0; j < m; ++j) {
            sort(cols[j].begin(), cols[j].end());
            
            long long col_total = 0;
            long long prefix_sum = 0;
            for (int i = 0; i < n; ++i) {
                col_total += (long long)i * cols[j][i] - prefix_sum;
                prefix_sum += cols[j][i];
            }
            total_winnings += col_total;
        }
        cout << total_winnings << "\n";
    }
    return 0;
}