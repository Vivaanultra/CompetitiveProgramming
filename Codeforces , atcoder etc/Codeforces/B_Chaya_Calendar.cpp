#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long current_year = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        // We need the smallest multiple of 'a' strictly greater than 'current_year'.
        // That is (current_year / a + 1) * a.
        current_year = (current_year / a + 1) * a;
    }
    cout << current_year << "\n";
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