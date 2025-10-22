#include <bits/stdc++.h>

using namespace std;

bool can_win(int k, int n, const vector<int>& a) {
    if (k == 0) {
        return true;
    }
    if (k > n) {
        return false;
    }

    multiset<int> s(a.begin(), a.end());

    for (int i = 1; i <= k; ++i) {
        int threshold = k - i + 1;

        auto it = s.upper_bound(threshold);
        if (it == s.begin()) {
            return false;
        }
        it = prev(it);
        s.erase(it);

        if (!s.empty()) {
            int smallest = *s.begin();
            s.erase(s.begin());
            s.insert(smallest + threshold);
        }
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_win(mid, n, a)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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