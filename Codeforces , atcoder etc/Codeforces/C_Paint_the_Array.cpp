#include <bits/stdc++.h>

using namespace std;

// Standard GCD function for long long
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // --- Try Pattern 1: RED, BLUE, RED... ---
    long long d1 = 0;
    for (int i = 0; i < n; i += 2) {
        if (d1 == 0) d1 = a[i];
        else d1 = gcd(d1, a[i]);
    }
    
    bool d1_is_valid = true;
    for (int i = 1; i < n; i += 2) {
        if (a[i] % d1 == 0) {
            d1_is_valid = false;
            break;
        }
    }
    
    if (d1_is_valid) {
        cout << d1 << endl;
        return;
    }

    // --- Try Pattern 2: BLUE, RED, BLUE... ---
    long long d2 = 0;
    for (int i = 1; i < n; i += 2) {
        if (d2 == 0) d2 = a[i];
        else d2 = gcd(d2, a[i]);
    }
    
    bool d2_is_valid = true;
    for (int i = 0; i < n; i += 2) {
        if (a[i] % d2 == 0) {
            d2_is_valid = false;
            break;
        }
    }

    if (d2_is_valid) {
        cout << d2 << endl;
        return;
    }

    // If both patterns fail
    cout << 0 << endl;
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