#include <bits/stdc++.h>

using namespace std;

const int MAX_X = 20;
vector<long long> p3(MAX_X + 2);
vector<long long> costs(MAX_X + 1);

void precompute() {
    p3[0] = 1;
    for (int i = 1; i < p3.size(); ++i) {
        p3[i] = p3[i - 1] * 3;
    }

    costs[0] = 3;
    for (int i = 1; i <= MAX_X; ++i) {
        costs[i] = p3[i + 1] + (long long)i * p3[i - 1];
    }
}

void solve() {
    long long n, k;
    cin >> n >> k;

    vector<long long> d(MAX_X + 2, 0);
    long long temp_n = n;
    int x = 0;
    long long min_deals = 0;
    int max_x = 0;

    while (temp_n > 0) {
        d[x] = temp_n % 3;
        min_deals += d[x];
        temp_n /= 3;
        if (d[x] > 0) max_x = x;
        x++;
    }

    if (min_deals > k) {
        cout << -1 << "\n";
        return;
    }

    long long deals_left = k - min_deals;
    long long current_cost = 0;
    for (int i = 0; i <= max_x + 1; ++i) {
        current_cost += d[i] * costs[i];
    }
    
    for (int i = max_x; i >= 1; --i) {
        long long savings = costs[i] - 3 * costs[i - 1];
        long long breakdowns_possible = deals_left / 2;
        long long breakdowns_to_do = min(breakdowns_possible, d[i]);
        
        current_cost -= breakdowns_to_do * savings;
        deals_left -= breakdowns_to_do * 2;
        
        d[i - 1] += breakdowns_to_do * 3;
    }

    cout << current_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}