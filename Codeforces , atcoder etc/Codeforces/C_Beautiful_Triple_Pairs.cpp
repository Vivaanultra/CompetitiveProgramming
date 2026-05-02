#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<pair<int, int>, int> ab;
        map<pair<int, int>, int> bc;
        map<pair<int, int>, int> ac;
        map<tuple<int, int, int>, int> abc;

        long long ans = 0;

        for (int i = 0; i < n - 2; i++) {
            int x = a[i];
            int y = a[i + 1];
            int z = a[i + 2];

            ans += ab[{x, y}] - abc[{x, y, z}];
            ans += bc[{y, z}] - abc[{x, y, z}];
            ans += ac[{x, z}] - abc[{x, y, z}];

            ab[{x, y}]++;
            bc[{y, z}]++;
            ac[{x, z}]++;
            abc[{x, y, z}]++;
        }

        cout << ans << endl;
    }
    return 0;
}