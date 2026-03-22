#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> l(n), u(n);
    vector<long long> sorted_l(n), sorted_u(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> u[i];
        sorted_l[i] = l[i];
        sorted_u[i] = u[i];
    }

    sort(sorted_l.begin(), sorted_l.end());
    sort(sorted_u.begin(), sorted_u.end());

    for (int i = 0; i < n; i++) {
        long long score = 0;
        score += sorted_l.end() - upper_bound(sorted_l.begin(), sorted_l.end(), l[i]);
        
        score += lower_bound(sorted_u.begin(), sorted_u.end(), u[i]) - sorted_u.begin();
        
        cout << score << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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