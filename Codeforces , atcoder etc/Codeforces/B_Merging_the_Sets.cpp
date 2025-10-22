#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> val_to_sets(m + 1);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            int val;
            cin >> val;
            val_to_sets[val].push_back(i);
        }
    }

    for (int j = 1; j <= m; ++j) {
        if (val_to_sets[j].empty()) {
            cout << "NO\n";
            return;
        }
    }

    map<vector<int>, int> class_map;
    for (int j = 1; j <= m; ++j) {
        sort(val_to_sets[j].begin(), val_to_sets[j].end());
        class_map[val_to_sets[j]]++;
    }

    set<int> essential_indices;
    for (auto const& [vec, count] : class_map) {
        if (vec.size() == 1) {
            essential_indices.insert(vec[0]);
        }
    }

    int p = essential_indices.size();
    int k = n - p;

    if (k >= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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