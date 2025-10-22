#include <bits/stdc++.h>

using namespace std;

vector<string> powers;

// Pre-computes all the powers of 2 up to 2^60 and stores them as strings.
void generate_powers() {
    for (int i = 0; i < 63; ++i) {
        unsigned long long p = 1ULL << i;
        powers.push_back(to_string(p));
    }
}

void solve() {
    string n_str;
    cin >> n_str;

    int min_moves = 1e9; // Initialize with a large number

    // Iterate through each pre-computed power of 2 string.
    for (const string& target : powers) {
        int s_ptr = 0;
        int t_ptr = 0;
        int matches = 0;

        // Play the "matching game" to find the number of shared digits.
        while (s_ptr < n_str.length() && t_ptr < target.length()) {
            if (n_str[s_ptr] == target[t_ptr]) {
                matches++;
                t_ptr++;
            }
            s_ptr++;
        }

        // Calculate the cost: erasures from source + additions for target.
        int current_moves = (n_str.length() - matches) + (target.length() - matches);
        min_moves = min(min_moves, current_moves);
    }

    cout << min_moves << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generate_powers();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}