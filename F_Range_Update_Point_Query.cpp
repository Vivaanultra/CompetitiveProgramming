#include <bits/stdc++.h>
using namespace std;

int get_digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    set<int> s;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 9) s.insert(i);
    }
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            auto it = s.lower_bound(l);
            while (it != s.end() && *it <= r) {
                a[*it] = get_digit_sum(a[*it]);
                if (a[*it] <= 9) {
                    it = s.erase(it);
                } else {
                    ++it;
                }
            }
        } else {
            int x;
            cin >> x;
            cout << a[x] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}