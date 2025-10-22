#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n, x;
        cin >> n >> x;
        vector<int> p;
        for (int i = 0; i < x; ++i) {
            p.push_back(i);
        }
        for (int i = x + 1; i < n; ++i) {
            p.push_back(i);
        }
        p.push_back(x);
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}