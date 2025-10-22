#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    int k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int max_len = 0;
    int current_len = 0;
    for (char c : s) {
        if (c == '1') {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 0;
        }
    }
    if (current_len > max_len) {
        max_len = current_len;
    }

    if (max_len >= k) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";

    int count_ones = 0;
    for (char c : s) {
        if (c == '1') {
            count_ones++;
        }
    }

    std::vector<int> p(n);
    int one_val = 1;
    int zero_val = count_ones + 1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            p[i] = one_val++;
        } else {
            p[i] = zero_val++;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}