#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    
    // Convert n to string to access digits easily
    string s = to_string(n);
    
    // Ensure the base string is sorted to generate permutations in correct order
    sort(s.begin(), s.end());
    
    vector<string> perms;
    do {
        perms.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    
    // Retrieve the specific permutations (converting 1-based index to 0-based)
    string code1 = perms[j - 1];
    string code2 = perms[k - 1];
    
    int A = 0;
    int len = code1.length();
    
    // Calculate A (matches in both value and position)
    for (int i = 0; i < len; i++) {
        if (code1[i] == code2[i]) {
            A++;
        }
    }
    
    // Since digits are distinct and sets are identical, B is simply remaining digits
    int B = len - A;
    
    cout << A << "A" << B << "B" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}