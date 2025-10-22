#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    // Calculate the sum of the first three digits.
    // s[i] - '0' converts a character digit to an integer.
    int sum_first_half = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    
    // Calculate the sum of the last three digits.
    int sum_second_half = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');

    if (sum_first_half == sum_second_half) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // It is currently Sunday, 10:52 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}