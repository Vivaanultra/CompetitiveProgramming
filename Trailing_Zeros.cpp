#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    long long ans = 0;
    for (long long i = 5; i <= n; i *= 5) {
        ans += n / i;
    }

    cout << ans << "\n";

    return 0;
}