#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> c(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Create the difference array c[i] = a[i] - b[i]
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] - b[i];
    }

    // Sort the difference array
    sort(c.begin(), c.end());

    long long good_pairs_count = 0;
    int l = 0, r = n - 1;

    while (l < r) {
        // If c[l] + c[r] is positive, a good pair is formed.
        if (c[l] + c[r] > 0) {
            // This means c[r] also forms a good pair with every element
            // from c[l] up to c[r-1], because they are all >= c[l].
            // There are (r - 1) - l + 1 = r - l such elements.
            good_pairs_count += (r - l);
            // We are done with c[r], so we move to a smaller right element.
            r--;
        } else {
            // c[l] is too small to form a good pair even with the largest
            // available element c[r]. So, we discard c[l].
            l++;
        }
    }

    cout << good_pairs_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // This problem has only one test case per run.
    solve();

    return 0;
}