#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<int> ind(m);
        for (int i = 0; i < m; i++) {
            cin >> ind[i];
            --ind[i];               // zero‑based
        }

        string c;
        cin >> c;

        // sort the replacement letters
        sort(c.begin(), c.end());

        // find the distinct positions we must write to
        sort(ind.begin(), ind.end());
        ind.erase(unique(ind.begin(), ind.end()), ind.end());
        int d = ind.size();

        // take the d smallest letters and assign them to the d positions in ascending order
        for (int k = 0; k < d; k++) {
            s[ind[k]] = c[k];
        }

        cout << s << "\n";
    }

    return 0;
}
