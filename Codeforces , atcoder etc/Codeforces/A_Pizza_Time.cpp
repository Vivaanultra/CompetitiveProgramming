#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    long long totalHao = 0;
    
    while (n > 2) {
        long long m1 = n / 3;
        totalHao += m1;
        long long m3 = n - 2 * m1;
        n = m3;
    }
    
    cout << totalHao << "\n";
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