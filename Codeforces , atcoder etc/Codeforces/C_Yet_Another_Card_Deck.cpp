#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> pos(51, 0);
    for (int i = 1; i <= n; ++i) {
        int color;
        cin >> color;
        if (pos[color] == 0) {
            pos[color] = i;
        }
    }

    for (int i = 0; i < q; ++i) {
        int query_color;
        cin >> query_color;

        int old_pos = pos[query_color];
        cout << old_pos << " ";

        for (int c = 1; c <= 50; ++c) {
            if (pos[c] < old_pos) {
                pos[c]++;
            }
        }
        pos[query_color] = 1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}