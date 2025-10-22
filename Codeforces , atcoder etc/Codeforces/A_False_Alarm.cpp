#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int first_closed_idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1 && first_closed_idx == -1) {
            first_closed_idx = i; // 0-indexed
        }
    }

    bool possible = false;
    // Iterate through all possible press times.
    // Yousef can press the button at any time t from 0 up to the moment he reaches
    // the first closed door (at time first_closed_idx).
    for (int press_time = 0; press_time <= first_closed_idx; ++press_time) {
        bool current_strategy_works = true;
        // Simulate the journey with this press_time
        for (int j = 0; j < n; ++j) {
            int arrival_time = j;
            bool is_open = (a[j] == 0);
            bool button_active = (arrival_time >= press_time && arrival_time < press_time + x);

            if (!is_open && !button_active) {
                // This door is closed and the button isn't active to open it.
                current_strategy_works = false;
                break;
            }
        }

        if (current_strategy_works) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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