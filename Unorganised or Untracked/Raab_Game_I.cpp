#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    
    if (a + b > n) {
        cout << "NO\n";
        return;
    }
    
    if ((a > 0 && b == 0) || (b > 0 && a == 0)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    
    vector<int> A_cards, B_cards;
    
    
    
    int ties = n - a - b;
    for (int i = 1; i <= ties; i++) {
        A_cards.push_back(i);
        B_cards.push_back(i);
    }

    
    
    vector<int> S;
    for (int i = ties + 1; i <= n; i++) {
        S.push_back(i);
    }

    
    for (int x : S) A_cards.push_back(x);

    if (!S.empty()) {
        int m = S.size();
        for (int i = 0; i < m; i++) {
            
            B_cards.push_back(S[(i + a) % m]);
        }
    }

    
    for (int i = 0; i < n; i++) cout << A_cards[i] << (i == n - 1 ? "" : " ");
    cout << "\n";

    
    for (int i = 0; i < n; i++) cout << B_cards[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
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