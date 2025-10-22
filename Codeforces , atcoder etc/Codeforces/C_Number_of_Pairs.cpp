#include <bits/stdc++.h>

using namespace std;

long long count_le(int val, int n, vector<int>& a) {
    long long count = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        if (a[left] + a[right] <= val) {
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }
    return count;
}

void solve() {
    int n;
    long long l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long count_r = count_le(r, n, a);
    long long count_l_minus_1 = count_le(l - 1, n, a);

    cout << count_r - count_l_minus_1 << endl;
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