#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int left = 0;
    int right = n - 1;
    char current_char = 'a' + n - 1;
    bool possible = true;

    while (left <= right) {
        if (s[right] == current_char) {
            right--;
        } else if (s[left] == current_char) {
            left++;
        } else {
            possible = false;
            break;
        }
        current_char--;
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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