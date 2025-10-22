#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long sum_of_mins = 0;
    long long sum_of_second_mins = 0;
    long long global_min_of_mins = 2e9;
    long long min_of_second_mins = 2e9;

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vector<int> a(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        
        sum_of_mins += a[0];
        sum_of_second_mins += a[1];
        global_min_of_mins = min(global_min_of_mins, (long long)a[0]);
        min_of_second_mins = min(min_of_second_mins, (long long)a[1]);
    }

    long long score_do_nothing = sum_of_mins;
    long long score_sacrifice_one = sum_of_second_mins - min_of_second_mins + global_min_of_mins;
    
    cout << max(score_do_nothing, score_sacrifice_one) << "\n";
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