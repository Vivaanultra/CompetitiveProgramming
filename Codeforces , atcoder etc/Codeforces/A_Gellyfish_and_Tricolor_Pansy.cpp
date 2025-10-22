#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long gellyfish_turns_to_win = min(b, d);
    long long flower_turns_to_win = min(a, c);

    if (gellyfish_turns_to_win <= flower_turns_to_win) {
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}