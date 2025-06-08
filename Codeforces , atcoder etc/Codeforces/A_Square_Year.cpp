#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int N = stoi(s);
        // Compute integer square‐root of N
        int r = int(round(sqrt(N)));
        if (1LL * r * r == N) {
            // (r + 0)^2 = N
            cout << r << " " << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
