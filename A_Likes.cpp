#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int pos_count = 0;
    int neg_count = 0;
    
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > 0) pos_count++;
        else neg_count++;
    }

    
    
    int current_likes = 0;
    for (int i = 0; i < pos_count; ++i) {
        current_likes++;
        cout << current_likes << " ";
    }
    for (int i = 0; i < neg_count; ++i) {
        current_likes--;
        cout << current_likes << " ";
    }
    cout << "\n";

    
    
    
    for (int i = 1; i <= n; ++i) {
        if (i <= 2 * neg_count) {
            
            cout << (i % 2) << " ";
        } else {
            
            cout << (i - 2 * neg_count) << " ";
        }
    }
    cout << "\n";
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