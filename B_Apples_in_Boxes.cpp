#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    long long sum = 0; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    
    if (a[n - 1] - a[0] > k) {
        
        
        
        
        if (a[n - 1] == a[n - 2]) {
            cout << "Jerry" << endl;
            return;
        }

        
        
        int new_max = max(a[n - 2], a[n - 1] - 1);
        if (new_max - a[0] > k) {
            cout << "Jerry" << endl;
            return;
        }

        
        
        if (sum % 2 == 1) {
            cout << "Tom" << endl;
        } else {
            cout << "Jerry" << endl;
        }
    } else {
        
        if (sum % 2 == 1) {
            cout << "Tom" << endl;
        } else {
            cout << "Jerry" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}