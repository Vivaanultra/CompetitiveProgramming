#include <bits/stdc++.h>

using namespace std;

long long count_inversions(int n, const vector<int>& a) {
    long long inversions = 0;
    long long ones = 0;
    for (int x : a) {
        if (x == 1) {
            ones++;
        } else {
            inversions += ones;
        }
    }
    return inversions;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total_zeros = 0;
    int total_ones = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) total_zeros++;
        else total_ones++;
    }

    // Baseline score with no flips
    long long max_inv = count_inversions(n, a);

    // Try flipping the first '0' we find
    vector<int> temp = a;
    for (int i = 0; i < n; ++i) {
        if (temp[i] == 0) {
            temp[i] = 1;
            max_inv = max(max_inv, count_inversions(n, temp));
            temp[i] = 0; // Flip back to original for next problem
            break;
        }
    }

    // Try flipping the last '1' we find
    temp = a;
    for (int i = n - 1; i >= 0; --i) {
        if (temp[i] == 1) {
            temp[i] = 0;
            max_inv = max(max_inv, count_inversions(n, temp));
            temp[i] = 1; // Flip back
            break;
        }
    }

    cout << max_inv << endl;
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