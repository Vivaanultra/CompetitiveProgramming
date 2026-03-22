#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool has_even = false, has_odd = false;
        for (int x : a) {
            if (x % 2 == 0) has_even = true;
            else has_odd = true;
        }

        if (has_even && has_odd) {
            sort(a.begin(), a.end());
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
