#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long m, a, b, c;
        cin >> m >> a >> b >> c;
        long long seated = min(a, m) + min(b, m);
        cout << min(seated + c, 2 * m) << "\n";
    }
    return 0;
}