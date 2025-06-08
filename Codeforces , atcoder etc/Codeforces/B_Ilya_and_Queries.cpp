#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();

    vector<int> prefix(n, 0);
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + (s[i] == s[i - 1] ? 1 : 0);
    }

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // convert to zero-based indexing
        l--; r--;
        cout << prefix[r] - prefix[l] << "\n";
    }

    return 0;
}
