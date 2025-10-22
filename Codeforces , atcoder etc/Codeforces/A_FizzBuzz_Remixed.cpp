#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long total_numbers = n + 1;
    long long num_blocks = total_numbers / 15;
    long long leftover_count = total_numbers % 15;
    long long result = num_blocks * 3;
    result += min(leftover_count, 3LL);
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}