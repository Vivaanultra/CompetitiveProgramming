#include <bits/stdc++.h>

using namespace std;

void solve();

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
void solve()
{
    int n;
    long long s;
    cin >> n >> s;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    long long cost1 = abs(s - x[0]) + (x[n - 1] - x[0]);
    long long cost2 = abs(s - x[n - 1]) + (x[n - 1] - x[0]);

    cout << min(cost1, cost2) << endl;
}