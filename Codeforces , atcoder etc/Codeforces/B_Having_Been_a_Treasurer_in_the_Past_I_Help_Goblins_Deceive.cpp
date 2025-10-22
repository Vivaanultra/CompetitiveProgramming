#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // First, count the number of dashes and underscores.
    long long dash_count = 0;
    long long underscore_count = 0;
    for (char c : s) {
        if (c == '-') {
            dash_count++;
        } else {
            underscore_count++;
        }
    }

    // To maximize the product x * y where x + y = dash_count,
    // we must make x and y as close as possible.
    long long x = dash_count / 2;
    long long y = dash_count - x; // This handles both even and odd dash_count

    // The total is the number of underscores multiplied by the product
    // of the two dash partitions.
    long long max_subsequences = underscore_count * x * y;

    cout << max_subsequences << "\n";
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