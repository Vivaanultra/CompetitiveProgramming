#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    double max_rate = 0.0;

    // Generate all substrings
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string t = s.substr(i, j - i + 1);
            int len_t = t.length();

            // Check if the substring is eligible for a non-zero rate
            if (len_t >= 3 && t.front() == 't' && t.back() == 't') {
                // Count the number of 't's
                int t_count = 0;
                for (char c : t) {
                    if (c == 't') {
                        t_count++;
                    }
                }
                
                // Calculate the rate
                double rate = (double)(t_count - 2) / (len_t - 2);
                max_rate = max(max_rate, rate);
            }
        }
    }

    // Output with required precision
    cout << fixed << setprecision(10) << max_rate << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // This problem doesn't have multiple test cases
    solve();

    return 0;
}