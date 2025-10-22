#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> b(7);
    for (int i = 0; i < 7; ++i) {
        cin >> b[i];
    }

    // The two smallest sums are the two smallest original numbers.
    int a1 = b[0];
    int a2 = b[1];

    // The largest sum is the sum of all three.
    // We can find the third number by subtraction.
    int a3 = b[6] - a1 - a2;

    cout << a1 << " " << a2 << " " << a3 << endl;
}

int main() {
    // It is currently Tuesday, 10:08 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}