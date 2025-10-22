#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        counts[a[i]]++;
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    bool possible = false;
    for (int day : a) {
        if (counts[day] >= 4) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes\n";
        return;
    }

    vector<int> strong_points;
    for (int day : a) {
        if (counts[day] >= 2) {
            strong_points.push_back(day);
        }
    }

    for (size_t i = 0; i < strong_points.size(); ++i) {
        for (size_t j = i + 1; j < strong_points.size(); ++j) {
            int start_day = strong_points[i];
            int end_day = strong_points[j];
            
            auto it1 = lower_bound(a.begin(), a.end(), start_day);
            auto it2 = lower_bound(a.begin(), a.end(), end_day);
            
            int dist_in_array = distance(it1, it2);
            int dist_in_days = end_day - start_day;

            if (dist_in_array == dist_in_days) {
                possible = true;
                break;
            }
        }
        if (possible) {
            break;
        }
    }

    if (possible) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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