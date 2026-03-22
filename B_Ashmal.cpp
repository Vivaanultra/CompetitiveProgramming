#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        string s = a[0];
        for (int i = 1; i < n; i++) {
            
            
            if (a[i] + s < s + a[i]) {
                s = a[i] + s;
            } else {
                s += a[i];
            }
        }
        cout << s << "\n";
    }
    return 0;
}