#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k;
    cin >> k;

    long long len = 1;
    long long count = 9;
    long long start = 1;

    // Step 1: Skip the blocks of numbers with fewer digits
    while (k > len * count) {
        k -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    // Step 2: Find the actual number
    long long target_number = start + (k - 1) / len;

    // Step 3: Find the specific digit
    string s = to_string(target_number);
    cout << s[(k - 1) % len] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}