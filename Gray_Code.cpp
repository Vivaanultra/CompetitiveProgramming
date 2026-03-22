#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int total = 1 << n;
    for (int i = 0; i < total; i++) {
        int gray = i ^ (i >> 1);
        
        string s = bitset<16>(gray).to_string();
        cout << s.substr(16 - n) << "\n";
    }

    return 0;
}