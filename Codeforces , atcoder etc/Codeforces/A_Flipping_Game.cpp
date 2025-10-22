#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int initial_ones = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            initial_ones++;
        }
    }

    if (initial_ones == n) {
        cout << n - 1 << "\n";
        return;
    }

    int max_gain = -1e9;
    for (int i = 0; i < n; ++i) {
        int current_gain = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] == 0) {
                current_gain++;
            } else {
                current_gain--;
            }
            max_gain = max(max_gain, current_gain);
        }
    }

    cout << initial_ones + max_gain << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // This problem format has n first, then the array. No t loop.
    solve();

    return 0;
}