#include <bits/stdc++.h>

using namespace std;

long long ask(int l, int r) {
    if (l >= r) return 0;
    cout << "? " << l << " " << r << endl;
    long long response;
    cin >> response;
    return response;
}

void solve() {
    int n;
    cin >> n;

    vector<long long> F(n + 1, 0);
    int first_k = -1;

    for (int i = 2; i <= n; ++i) {
        F[i] = ask(1, i);
        if (F[i] > 0 && first_k == -1) {
            first_k = i;
        }
    }

    if (first_k == -1) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    string s = "";
    long long zeros_count = 0;

    long long val_k = F[first_k];
    long long initial_zeros = val_k;
    long long initial_ones = first_k - 1 - initial_zeros;

    for (int i = 0; i < initial_ones; ++i) {
        s += '1';
    }
    for (int i = 0; i < initial_zeros; ++i) {
        s += '0';
    }
    s += '1';
    zeros_count = initial_zeros;

    for (int i = first_k + 1; i <= n; ++i) {
        long long diff = F[i] - F[i - 1];
        if (diff == 0) {
            s += '0';
            zeros_count++;
        } else {
            // Here, diff must be equal to zeros_count
            s += '1';
        }
    }

    cout << "! " << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}