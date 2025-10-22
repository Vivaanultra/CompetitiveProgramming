#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long result = (n * n) / 4 + 1;
    cout << result << endl;
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