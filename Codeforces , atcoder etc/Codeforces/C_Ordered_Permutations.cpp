#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (n < 62 && k > (1LL << (n - 1))) {
        cout << "-1\n";
        return;
    }

    deque<int> dq;
    vector<int> p(n);
    int l = 0, r = n - 1;
    
    
    long long target = k - 1;

    for (int i = 1; i < n; ++i) {
        
        
        int decisions_remaining = n - 1 - i;
        
        
        
        
        bool go_right = false;
        
        if (decisions_remaining < 60) {
            if ((target >> decisions_remaining) & 1) {
                go_right = true;
            }
        }

        if (go_right) {
            p[r] = i;
            r--;
        } else {
            p[l] = i;
            l++;
        }
    }

    
    p[l] = n;

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
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