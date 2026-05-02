#include <iostream>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    if (N == 1) {
        cout << 0 << endl;
        return;
    }

    long long M = N - 1;     
    long long K = M / 2;     
    long long rem = M % 2;   
    
    long long sum_mins = K * (K + 1) + rem * (K + 1);
    
    cout << sum_mins - M << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}