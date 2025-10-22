#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long robin_gold = 0;
    int people_helped = 0;

    // Encounter each person in order
    for (int i = 0; i < n; ++i) {
        if (a[i] >= k) {
            // Robin takes from the rich
            robin_gold += a[i];
        } else if (a[i] == 0) {
            // Robin gives to the poor, if he can
            if (robin_gold > 0) {
                robin_gold--;
                people_helped++;
            }
        }
    }

    cout << people_helped << endl;
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