#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    
    sort(a.begin(), a.end());

    int colors = 0;
    
    vector<bool> used(n, false);

    for (int i = 0; i < n; ++i) {
        
        if (!used[i]) {
            colors++;
            
            
            for (int j = i; j < n; ++j) {
                if (!used[j] && a[j] % a[i] == 0) {
                    used[j] = true;
                }
            }
        }
    }

    cout << colors << endl;

    return 0;
}