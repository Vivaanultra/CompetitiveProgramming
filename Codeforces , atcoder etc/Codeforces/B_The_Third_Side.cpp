#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
    }

    long long result = sum - (n - 1);
    cout << result << "\n";
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