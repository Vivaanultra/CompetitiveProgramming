#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int bit[MAXN];
int N_BIT;

void update(int idx, int val) {
    for (++idx; idx <= N_BIT; idx += idx & -idx) {
        bit[idx] += val;
    }
}

int query(int idx) {
    int sum = 0;
    for (++idx; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> unique_vals;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        unique_vals.push_back(a[i]);
    }

    // Coordinate Compression
    sort(unique_vals.begin(), unique_vals.end());
    unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
    
    N_BIT = unique_vals.size();
    for (int i = 0; i <= N_BIT; ++i) {
        bit[i] = 0;
    }

    long long total_inversions = 0;
    for (int i = 0; i < n; ++i) {
        // Find the compressed rank of the current number
        int rank = lower_bound(unique_vals.begin(), unique_vals.end(), a[i]) - unique_vals.begin();

        // Query the Fenwick tree to find costs
        int count_smaller = query(rank - 1);
        int count_total = i;
        int count_larger = count_total - query(rank);

        // Add the minimum of the two costs to the total
        total_inversions += min(count_smaller, count_larger);

        // Add the current number to the Fenwick tree
        update(rank, 1);
    }

    cout << total_inversions << endl;
}

int main() {
    // It is currently Sunday, 12:20 AM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}