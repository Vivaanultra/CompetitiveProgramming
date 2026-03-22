#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> p;
        p.push_back(0); 
        
        long long current_sum = 0;
        long long max_prev_p = -2e18; 
        long long operations = 0;

        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2 != 0) {
                current_sum -= a[i];
            } else {
                current_sum += a[i];
            }

            if (i >= 1) {
                max_prev_p = max(max_prev_p, p[i - 1]);
            }

            if (current_sum < max_prev_p) {
                long long diff = max_prev_p - current_sum;
                operations += diff;
                current_sum += diff;
            }

            p.push_back(current_sum);
        }

        cout << operations << "\n";
    }
    return 0;
}