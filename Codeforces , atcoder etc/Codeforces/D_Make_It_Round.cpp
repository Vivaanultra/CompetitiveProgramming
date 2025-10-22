#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;

    long long original_n = n;
    int count2 = 0;
    int count5 = 0;

    long long temp_n = n;
    while (temp_n > 0 && temp_n % 2 == 0) {
        count2++;
        temp_n /= 2;
    }

    while (temp_n > 0 && temp_n % 5 == 0) {
        count5++;
        temp_n /= 5;
    }

    long long k = 1;

    while (count2 < count5 && k * 2 <= m) {
        k *= 2;
        count2++;
    }

    while (count5 < count2 && k * 5 <= m) {
        k *= 5;
        count5++;
    }

    while (k * 10 <= m) {
        k *= 10;
    }
    
    long long final_k = k * (m / k);
    cout << original_n * final_k << endl;
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