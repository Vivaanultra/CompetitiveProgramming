#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        long long a_i;
        cin >> a_i;
        b[i] = a_i - (i + 1);
    }

    sort(b.begin(), b.end());

    long long total_pairs = 0;
    int i = 0;
    while (i < n) {
        long long current_val = b[i];
        long long count = 0;
        while (i < n && b[i] == current_val) {
            count++;
            i++;
        }
        total_pairs += (count * (count - 1)) / 2;
    }

    cout << total_pairs << endl;
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