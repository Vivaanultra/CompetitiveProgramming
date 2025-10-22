#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long ans_a, ans_b, ans_c;

    // Calculate votes needed for candidate A to win
    ans_a = max(0LL, max(b, c) + 1 - a);

    // Calculate votes needed for candidate B to win
    ans_b = max(0LL, max(a, c) + 1 - b);

    // Calculate votes needed for candidate C to win
    ans_c = max(0LL, max(a, b) + 1 - c);

    cout << ans_a << " " << ans_b << " " << ans_c << endl;
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