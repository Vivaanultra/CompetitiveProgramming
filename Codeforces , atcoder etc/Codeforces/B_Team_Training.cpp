#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    int teams = 0;
    int current_team_size = 0;
    for (int i = 0; i < n; ++i) {
        current_team_size++;
        if (a[i] * current_team_size >= x) {
            teams++;
            current_team_size = 0;
        }
    }
    cout << teams << endl;
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