#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long s, x;
    cin >> s >> x;

    if (s < x) {
        cout << 0 << "\n";
        return 0;
    }

    long long diff = s - x;
    if (diff % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long c = diff / 2;
    if ((c & x) != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long ans = (1LL << __builtin_popcountll(x));

    if (s == x) {
        ans -= 2;
    }

    cout << ans << "\n";

    return 0;
}