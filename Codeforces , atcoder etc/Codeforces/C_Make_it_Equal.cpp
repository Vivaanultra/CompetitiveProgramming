#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    map<long long, int> s_fingerprints;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        long long rem = val % k;
        s_fingerprints[min(rem, k - rem)]++;
    }

    map<long long, int> t_fingerprints;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        long long rem = val % k;
        t_fingerprints[min(rem, k - rem)]++;
    }

    if (s_fingerprints == t_fingerprints) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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