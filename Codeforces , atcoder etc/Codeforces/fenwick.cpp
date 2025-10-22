#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> bit(n + 1, 0);

    while (q--) {
        char type;
        cin >> type;
        if (type == '+') {
            int idx;
            long long delta;
            cin >> idx >> delta;
            
            idx++;
            
            while (idx <= n) {
                bit[idx] += delta;
                idx += (idx & -idx);
            }
        } else {
            int idx;
            cin >> idx;
            
            long long sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= (idx & -idx);
            }
            cout << sum << "\n";
        }
    }

    return 0;
}