#include<bits/stdc++.h>
using namespace std;

long long gcd_val(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long w, h, d, n;
    if (cin >> w >> h >> d >> n) {
        long long a = gcd_val(w, n);
        n /= a;
        
        long long b = gcd_val(h, n);
        n /= b;
        
        long long c = gcd_val(d, n);
        n /= c;

        if (n == 1) {
            cout << (a - 1) << " " << (b - 1) << " " << (c - 1) << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}