#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (n == k) {
        cout << string(n, '-') << "\n";
        return;
    }

    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    for (char c : s) {
        if (c == '0') count_0++;
        else if (c == '1') count_1++;
        else count_2++;
    }

    string ans(n, '?');
    for (int i = 0; i < count_0; ++i) {
        ans[i] = '-';
    }
    for (int i = 0; i < count_1; ++i) {
        ans[n - 1 - i] = '-';
    }
    int intersection_start_idx = count_0 + count_2; 
    int intersection_end_idx = n - k + count_0 - 1;  

    if (intersection_start_idx <= intersection_end_idx) {
        for (int i = intersection_start_idx; i <= intersection_end_idx; ++i) {
            ans[i] = '+';
        }
    }

    cout << ans << "\n";
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

