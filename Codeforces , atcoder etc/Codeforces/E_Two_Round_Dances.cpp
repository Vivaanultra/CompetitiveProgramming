#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }

    long long k = n / 2;
    long long ans = fact / (2 * k * k);

    cout << ans << endl;

    return 0;
}