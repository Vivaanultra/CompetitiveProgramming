#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n + 1, 0);
    int c = 0, mx = 0;
    
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        if (v[x] == 0) {
            v[x] = 1;
            c++;
            mx = max(mx, c);
        } else {
            c--;
        }
    }
    
    cout << mx << endl;
    
    return 0;
}