#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    
    multiset<int> towers;

    for (int i = 0; i < n; i++) {
        int cube_size;
        cin >> cube_size;

        
        auto it = towers.upper_bound(cube_size);

        if (it != towers.end()) {
            
            
            towers.erase(it);
            
            towers.insert(cube_size);
        } else {
            
            
            towers.insert(cube_size);
        }
    }

    
    cout << towers.size() << "\n";

    return 0;
}