#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    list<int> candidates;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        candidates.push_back(x);
    }

    vector<int> result;
    int current_or = 0;

    // We only need to be careful for about 30-40 steps, or until n becomes 0.
    for (int i = 0; i < n && i < 40; ++i) {
        int max_or_val = -1;
        int best_elem = -1;
        list<int>::iterator best_it;

        // Find the best element among the remaining candidates
        for (auto it = candidates.begin(); it != candidates.end(); ++it) {
            if ((current_or | *it) > max_or_val) {
                max_or_val = (current_or | *it);
                best_elem = *it;
                best_it = it;
            }
        }
        
        // If no element improves the OR, we are done with the interesting part
        if (max_or_val == current_or) {
            break;
        }

        result.push_back(best_elem);
        current_or |= best_elem;
        candidates.erase(best_it);
    }

    // Add any remaining numbers, their order doesn't matter anymore
    for (int x : candidates) {
        result.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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