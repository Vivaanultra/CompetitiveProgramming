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
        string b;
        cin >> b;

        string r = b;
        sort(r.begin(), r.end());
        r.erase(unique(r.begin(), r.end()), r.end());

        vector<char> mp(256);
        int m = r.size();
        for (int i = 0; i < m; i++) {
            mp[r[i]] = r[m - 1 - i];
        }

        for (int i = 0; i < n; i++) {
            cout << mp[b[i]];
        }
        cout << endl;
    }
    return 0;
}