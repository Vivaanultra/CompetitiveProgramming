#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    long long count_even = 0;
    long long sum_even = 0;
    long long count_odd = 0;
    long long sum_odd = 0;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            count_even++;
            sum_even += val;
        } else {
            count_odd++;
            sum_odd += val;
        }
    }

    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type >> x;

        if (type == 0) { // Add to even
            if (x % 2 == 0) { // Even + Even = Even
                sum_even += count_even * x;
            } else { // Even + Odd = Odd
                sum_odd += sum_even + count_even * x;
                sum_even = 0;
                count_odd += count_even;
                count_even = 0;
            }
        } else { // Add to odd
            if (x % 2 == 0) { // Odd + Even = Odd
                sum_odd += count_odd * x;
            } else { // Odd + Odd = Even
                sum_even += sum_odd + count_odd * x;
                sum_odd = 0;
                count_even += count_odd;
                count_odd = 0;
            }
        }
        cout << sum_even + sum_odd << "\n";
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