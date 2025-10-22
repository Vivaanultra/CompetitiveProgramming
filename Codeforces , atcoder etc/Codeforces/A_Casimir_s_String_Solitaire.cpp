#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int countA = 0;
    int countB = 0;
    int countC = 0;

    for (char c : s) {
        if (c == 'A') {
            countA++;
        } else if (c == 'B') {
            countB++;
        } else {
            countC++;
        }
    }

    if (countB == countA + countC) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // It is currently 11:30 PM on Saturday in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
} 