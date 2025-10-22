#include <bits/stdc++.h>
using namespace std;

long long calculate_min_swaps(const string& s, char target_char) {
    vector<int> positions;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == target_char) {
            positions.push_back(i);
        }
    }

    if (positions.empty()) {
        return 0;
    }

    vector<long long> q_values;
    for (int i = 0; i < positions.size(); ++i) {
        q_values.push_back(positions[i] - i);
    }

    long long median = q_values[q_values.size() / 2];
    long long total_cost = 0;
    for (long long val : q_values) {
        total_cost += abs(val - median);
    }
    
    return total_cost;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long cost_a = calculate_min_swaps(s, 'a');
    long long cost_b = calculate_min_swaps(s, 'b');

    cout << min(cost_a, cost_b) << "\n";
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