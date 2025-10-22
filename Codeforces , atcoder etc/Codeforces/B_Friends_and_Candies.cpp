#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n != 0) {
        cout << -1 << endl;
        return;
    }

    long long avg = sum / n;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > avg) {
            k++;
        }
    }

    cout << k << endl;
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