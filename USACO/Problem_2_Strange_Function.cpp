#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long B(const string& s) {
    long long val = 0;
    for (char c : s) {
        val = (val * 2 + (c - '0')) % MOD;
    }
    return val;
}

void solve() {
    string s;
    cin >> s;
    
    bool binary_like = true;
    for (char c : s) {
        if (c != '0' && c != '1') {
            binary_like = false;
            break;
        }
    }
    
    long long ElsieNumber = 0;
    
    if (binary_like) {
        string s2 = s.length() > 1 ? s.substr(0, s.length() - 1) : "";
        ElsieNumber = (B(s) + B(s2)) % MOD;
    } else {
        string s_prime = "";
        for (char c : s) {
            s_prime += ((c - '0') % 2) ? '1' : '0';
        }
        string s_prime2 = s_prime.length() > 1 ? s_prime.substr(0, s_prime.length() - 1) : "";
        ElsieNumber = (1 + B(s_prime) + B(s_prime2)) % MOD;
    }
    
    cout << ElsieNumber << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}