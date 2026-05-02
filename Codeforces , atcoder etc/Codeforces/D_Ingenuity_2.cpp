#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[s[i]].push_back(i);
    }

    // Check 1: Total displacement parity must allow meeting
    if ((pos['N'].size() + pos['S'].size()) % 2 != 0 || 
        (pos['E'].size() + pos['W'].size()) % 2 != 0) {
        return "NO";
    }

    // Check 2: The "Empty Move" edge case.
    // If we have exactly 1 N and 1 S (and nothing else), we are forced to give
    // both to one person (to net 0), leaving the other with nothing.
    if (pos['N'].size() == 1 && pos['S'].size() == 1 && pos['E'].empty() && pos['W'].empty()) return "NO";
    if (pos['E'].size() == 1 && pos['W'].size() == 1 && pos['N'].empty() && pos['S'].empty()) return "NO";

    string ans(n, ' ');

    // Strategy:
    // 1. Assign pairs of (N,N), (S,S), (E,E), (W,W) alternatingly to R and H.
    // 2. If N and S counts are odd, assign the final single N and S to 'R'.
    // 3. If E and W counts are odd, assign the final single E and W to 'H'.
    
    // Helper lambda to assign pairs
    auto assign_pairs = [&](char type, char p1, char p2) {
        for (size_t i = 0; i + 1 < pos[type].size(); i += 2) {
            ans[pos[type][i]] = p1;
            ans[pos[type][i+1]] = p2;
        }
    };

    // Distribute pairs
    assign_pairs('N', 'R', 'H');
    assign_pairs('S', 'R', 'H');
    assign_pairs('E', 'R', 'H');
    assign_pairs('W', 'R', 'H');

    // Handle odd remainders
    // If N is odd, S must be odd (due to parity check). Assign last ones to R.
    if (pos['N'].size() % 2 == 1) {
        ans[pos['N'].back()] = 'R';
        ans[pos['S'].back()] = 'R';
    }

    // If E is odd, W must be odd. Assign last ones to H.
    // Note: We use H here specifically to avoid the "one person takes all" issue
    // if both dimensions have remainders.
    if (pos['E'].size() % 2 == 1) {
        ans[pos['E'].back()] = 'H';
        ans[pos['W'].back()] = 'H';
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}