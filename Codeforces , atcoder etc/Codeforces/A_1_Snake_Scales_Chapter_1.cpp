#include <bits/stdc++.h>
using namespace std;

void solve(int case_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "Case #" << case_num << ": 0\n";
        return;
    }

    int max_diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        int diff = abs(a[i] - a[i + 1]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    cout << "Case #" << case_num << ": " << max_diff << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}