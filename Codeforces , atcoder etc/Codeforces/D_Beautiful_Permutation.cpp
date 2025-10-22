#include <bits/stdc++.h>
using namespace std;

long long query(int type, int l, int r) {
    cout << type << " " << l << " " << r << endl;
    long long sum;
    cin >> sum;
    return sum;
}

void solve() {
    int n;
    cin >> n;

    int l_ans = n;
    int low = 1, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long sum_p = query(1, 1, mid);
        long long sum_a = query(2, 1, mid);
        if (sum_a > sum_p) {
            l_ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    long long total_diff = query(2, 1, n) - query(1, 1, n);
    int r_ans = total_diff + l_ans - 1;

    cout << "! " << l_ans << " " << r_ans << endl;
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