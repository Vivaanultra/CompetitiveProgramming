#include <iostream>

using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;

    if ((n - a) % 2 == 0 && (n - b) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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