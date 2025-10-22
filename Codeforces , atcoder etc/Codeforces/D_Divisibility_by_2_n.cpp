#include <bits/stdc++.h>

using namespace std;

int count_factors_of_2(int num) {
    int count = 0;
    while (num > 0 && num % 2 == 0) {
        count++;
        num /= 2;
    }
    return count;
}

void solve() {
    int n;
    cin >> n;
    
    long long current_factors = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        current_factors += count_factors_of_2(val);
    }

    vector<int> gains;
    for (int i = 1; i <= n; ++i) {
        gains.push_back(count_factors_of_2(i));
    }

    sort(gains.rbegin(), gains.rend());

    int ops = 0;
    for (int gain : gains) {
        if (current_factors >= n) {
            break;
        }
        current_factors += gain;
        ops++;
    }

    if (current_factors >= n) {
        cout << ops << "\n";
    } else {
        cout << -1 << "\n";
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