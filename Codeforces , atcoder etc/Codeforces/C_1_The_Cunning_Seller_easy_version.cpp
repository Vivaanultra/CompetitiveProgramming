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
    long long n;
    cin >> n;

    long long total_cost = 0;
    int x = 0;
    while (n > 0) {
        int digit = n % 3;
        total_cost += (long long)digit * costs[x];
        n /= 3;
        x++;
    }
    cout << total_cost << "\n";
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