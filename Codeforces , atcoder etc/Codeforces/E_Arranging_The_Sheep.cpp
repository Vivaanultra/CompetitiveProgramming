#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<long long> sheep_indices;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            sheep_indices.push_back(i);
        }
    }

    if (sheep_indices.size() <= 1) {
        cout << 0 << endl;
        return;
    }

    long long k = sheep_indices.size();
    long long median_index_val = sheep_indices[k / 2];
    
    long long moves = 0;
    for (int i = 0; i < k; ++i) {
        long long target_pos = median_index_val - (k / 2) + i;
        moves += abs(sheep_indices[i] - target_pos);
    }

    cout << moves << endl;
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