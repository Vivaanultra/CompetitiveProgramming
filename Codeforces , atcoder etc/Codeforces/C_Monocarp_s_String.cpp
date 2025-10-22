#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_a = 0;
    int total_b = 0;
    for (char c : s) {
        if (c == 'a') {
            total_a++;
        } else {
            total_b++;
        }
    }

    if (total_a == total_b) {
        cout << 0 << "\n";
        return;
    }

    int diff = total_a - total_b;
    map<int, int> last_occurrence;
    last_occurrence[0] = 0;
    int balance = 0;
    int min_len = n;

    for (int j = 1; j <= n; ++j) {
        if (s[j - 1] == 'a') {
            balance++;
        } else {
            balance--;
        }

        int target_balance = balance - diff;
        if (last_occurrence.count(target_balance)) {
            int i = last_occurrence[target_balance];
            min_len = min(min_len, j - i);
        }
        
        last_occurrence[balance] = j;
    }
    
    if (min_len == n) {
        cout << -1 << "\n";
    } else {
        cout << min_len << "\n";
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

