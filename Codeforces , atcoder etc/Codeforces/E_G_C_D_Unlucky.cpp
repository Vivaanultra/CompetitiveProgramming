#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> p(n), s(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) cin >> s[i];

    if (n == 1) {
        cout << "Yes\n";
        return;
    }

    if (p[n - 1] != s[0]) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (p[i] % p[i + 1] != 0 || s[i + 1] % s[i] != 0) {
            cout << "No\n";
            return;
        }
    }
    
    if (std::gcd(p[0], s[1]) != s[0]) {
         cout << "No\n";
         return;
    }
    
    if (std::gcd(p[n - 2], s[n - 1]) != p[n - 1]) {
        cout << "No\n";
        return;
    }

    for (int i = 1; i < n - 1; ++i) {
        long long common_divisor = std::gcd(p[i - 1], s[i + 1]);
        
        unsigned __int128 p_val = p[i];
        unsigned __int128 s_val = s[i];
        unsigned __int128 common_multiple = (p_val * s_val) / std::gcd(p[i], s[i]);

        if (common_divisor % common_multiple != 0) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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