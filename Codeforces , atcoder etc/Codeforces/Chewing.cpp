#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        long long partner_limit = k - h[i];
        
        auto it = lower_bound(h.begin() + i + 1, h.end(), partner_limit);
        
        count += distance(h.begin() + i + 1, it);
    }

    cout << count << "\n";

    return 0;
}