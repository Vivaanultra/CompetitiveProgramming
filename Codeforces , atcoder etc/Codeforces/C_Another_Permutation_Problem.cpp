#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        long long n;
        cin >> n;
        long long sumsq = n * (n + 1) * (2 * n + 1) / 6; // sum of i^2
        long long ans = sumsq - 1 - n * (n - 1);
        cout << ans << '\n';
    }
    return 0;
}
