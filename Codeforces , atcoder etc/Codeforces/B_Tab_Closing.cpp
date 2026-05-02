#include <iostream>

using namespace std;

void solve() {
    long long a, b, n;
    cin >> a >> b >> n;

    
    
    if (b == a) {
        cout << 1 << endl;
        return;
    }

    
    
    long long k = (a - 1) / b;

    
    
    if (n <= k) {
        cout << 1 << endl;
        return;
    }

    
    
    
    
    
    
    
    
    
    if (n == k + 1 && (n * b) % a == 0) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
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