#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long suffix_gcd = 0;
    long long required_lcm = 1;

    for (int i = n - 1; i >= 0; --i) {
        suffix_gcd = std::gcd(suffix_gcd, a[i]);
        required_lcm = std::lcm(required_lcm, a[i] / suffix_gcd);
    }
    
    cout << required_lcm << endl;
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