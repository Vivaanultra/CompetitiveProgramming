#include <bits/stdc++.h>

using namespace std;

void solve() {
    string n;
    cin >> n;
    const string PI = "3141592653589793238462643383279";
    int count = 0;
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] == PI[i]) {
            count++;
        } else {
            break;
        }
    }
    cout << count << endl;
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