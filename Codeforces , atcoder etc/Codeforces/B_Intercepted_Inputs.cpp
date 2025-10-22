#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<long long> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long target_product = (long long)k - 2;
    int left = 0;
    int right = k - 1;

    while (left < right) {
        long long current_product = a[left] * a[right];
        if (current_product == target_product) {
            cout << a[left] << " " << a[right] << endl;
            return;
        }
        if (current_product < target_product) {
            left++;
        } else {
            right--;
        }
    }
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