#include <bits/stdc++.h>

using namespace std;

// Function to check if a string is a valid Regular Bracket Sequence (RBS)
// This can be done with a simple balance counter, which is equivalent to a stack for this problem.
// A positive balance means we have open brackets waiting to be closed (pushed onto a stack).
// A negative balance means we have a closing bracket without a matching open one.
bool is_rbs(const string& s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else {
            balance--;
        }
        // If balance goes below zero at any point, it's invalid.
        if (balance < 0) {
            return false;
        }
    }
    // A valid RBS must end with a balance of exactly 0.
    return balance == 0;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    // 1. Calculate how many '(' and ')' are needed.
    int open_needed = n / 2;
    vector<int> q_indices; // Store indices of '?'
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            open_needed--;
        }
        if (s[i] == '?') {
            q_indices.push_back(i);
        }
    }
    
    // The number of '?'s that need to become ')' is total '?'s minus those that become '('.
    int close_needed = q_indices.size() - open_needed;

    // If all '?' must become '(' or all must become ')', the solution is trivially unique.
    if (open_needed == 0 || close_needed == 0) {
        cout << "YES" << endl;
        return;
    }

    // 2. Construct the first potential RBS (s1) by greedily filling '?'.
    // The first 'open_needed' '?'s become '(' and the rest become ')'.
    string s1 = s;
    for (int i = 0; i < q_indices.size(); ++i) {
        if (i < open_needed) {
            s1[q_indices[i]] = '(';
        } else {
            s1[q_indices[i]] = ')';
        }
    }

    // 3. Construct a second potential RBS (s2) by swapping.
    // We swap the last '?' that became '(' with the first '?' that became ')'.
    // This is the "closest" possible swap to maintain validity.
    string s2 = s1;
    swap(s2[q_indices[open_needed - 1]], s2[q_indices[open_needed]]);
    
    // 4. Check if the swapped version (s2) is also a valid RBS.
    // The problem guarantees s1 will be valid.
    // If s2 is also valid, then the solution is not unique.
    if (is_rbs(s2)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}