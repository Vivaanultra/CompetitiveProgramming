#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    unordered_map<long long, int> counts;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        counts[a[i]]++;
    }

    long long start_node = 0;
    for (long long val : a) {
        bool has_predecessor = false;
        if (val % 2 == 0 && counts.count(val / 2)) {
            has_predecessor = true;
        }
        if (counts.count(val * 3)) {
            has_predecessor = true;
        }
        
        if (!has_predecessor) {
            start_node = val;
            break;
        }
    }

    vector<long long> result;
    long long current = start_node;
    for (int i = 0; i < n; ++i) {
        result.push_back(current);
        
        if (counts.count(current * 2)) {
            current = current * 2;
        } else if (current % 3 == 0 && counts.count(current / 3)) {
            current = current / 3;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}