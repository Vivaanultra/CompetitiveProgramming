#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long initial_inversions = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                initial_inversions++;
            }
        }
    }

    long long min_inversions = initial_inversions;
    int best_l = 1;
    int best_r = 1;

    for (int l = 0; l < n; ++l) {
        int lesser = 0;
        int greater = 0;
        for (int r = l + 1; r < n; ++r) {
            if (a[r] < a[l]) {
                lesser++;
            } else if (a[r] > a[l]) {
                greater++;
            }
            
            long long change = greater - lesser;
            long long current_inversions = initial_inversions + change;

            if (current_inversions < min_inversions) {
                min_inversions = current_inversions;
                best_l = l + 1;
                best_r = r + 1;
            }
        }
    }

    cout << best_l << " " << best_r << "\n";
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