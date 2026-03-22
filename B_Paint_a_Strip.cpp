#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int current_len = 1;
    int ops = 1;

    while (current_len < n) 
    {
        current_len = (current_len + 1) * 2;
        ops++;
    }

    cout << ops << "\n";
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