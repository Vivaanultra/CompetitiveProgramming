#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long total_sum = 0;
    vector<int> odds;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        total_sum += val;
        if (val % 2 != 0) {
            odds.push_back(val);
        }
    }

    if (odds.empty()) {
        // If there are no odd fields, the mower never turns on.
        // We cut 0 dandelions.
        cout << 0 << "\n";
        return;
    }

    sort(odds.begin(), odds.end());

    int num_to_lose = odds.size() / 2;
    long long loss_sum = 0;
    for (int i = 0; i < num_to_lose; ++i) {
        loss_sum += odds[i];
    }

    cout << total_sum - loss_sum << "\n";
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