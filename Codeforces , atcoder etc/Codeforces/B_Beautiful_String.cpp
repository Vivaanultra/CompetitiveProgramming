#include <bits/stdc++.h>

using namespace std;

bool is_non_decreasing(const string& p) {
    for (size_t i = 1; i < p.length(); ++i) {
        if (p[i] < p[i - 1]) {
            return false;
        }
    }
    return true;
}

bool is_palindrome(const string& x) {
    string reversed_x = x;
    reverse(reversed_x.begin(), reversed_x.end());
    return x == reversed_x;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int mask = 0; mask < (1 << n); ++mask) {
        string p_str = "";
        string x_str = "";
        vector<int> p_indices;

        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                p_str += s[i];
                p_indices.push_back(i + 1);
            } else {
                x_str += s[i];
            }
        }

        if (is_non_decreasing(p_str) && is_palindrome(x_str)) {
            cout << p_indices.size() << endl;
            for (int i = 0; i < p_indices.size(); ++i) {
                cout << p_indices[i] << (i == p_indices.size() - 1 ? "" : " ");
            }
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
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