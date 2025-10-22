#include <iostream>
using namespace std;
// Use a function to process each query
void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long total_sum = a + b + c;
    cout << total_sum / 2 << "\n";
}

int main() {
    // Standard competitive programming setup for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}