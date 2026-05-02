#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    
    long long total_sum = 0;
    for(int i = 0; i < n - 1; ++i) {
        total_sum += abs(a[i] - a[i+1]);
    }

    long long max_reduction = 0;

    
    
    max_reduction = max(max_reduction, (long long)abs(a[0] - a[1]));

    
    
    max_reduction = max(max_reduction, (long long)abs(a[n-2] - a[n-1]));

    
    
    for(int i = 1; i < n - 1; ++i) {
        long long original_dist = abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]);
        long long new_dist = abs(a[i-1] - a[i+1]);
        max_reduction = max(max_reduction, original_dist - new_dist);
    }

    cout << total_sum - max_reduction << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}