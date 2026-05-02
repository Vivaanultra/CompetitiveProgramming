#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> evens, odds;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) evens.push_back(a[i]);
        else odds.push_back(a[i]);
    }

    // Case 1: Any two even numbers work
    if (evens.size() >= 2) {
        cout << evens[0] << " " << evens[1] << "\n";
        return;
    }

    // Case 2: Consecutive odds with small gap (quotient is 1 -> remainder is even)
    // If the array is large, this loop finds a pair quickly.
    if (odds.size() >= 2) {
        for (size_t i = 0; i < odds.size() - 1; ++i) {
            if (odds[i+1] < 2LL * odds[i]) {
                cout << odds[i] << " " << odds[i+1] << "\n";
                return;
            }
        }
    }

    // Case 3: Small N brute force
    // If we reach here, the sequence grows exponentially, so N is very small (~30).
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((a[j] % a[i]) % 2 == 0) {
                cout << a[i] << " " << a[j] << "\n";
                return;
            }
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}