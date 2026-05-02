#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    
    sort(b.begin(), b.end());

    string s;
    cin >> s;

    
    
    
    vector<vector<int>> die_left(k + 1);
    vector<vector<int>> die_right(k + 1);

    for (int i = 0; i < n; ++i) {
        
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        
        
        if (it != b.end()) {
            long long dist = (long long)*it - a[i];
            if (dist <= k) {
                die_right[dist].push_back(i);
            }
        }
        
        
        
        if (it != b.begin()) {
            long long dist = (long long)a[i] - *prev(it);
            if (dist <= k) {
                die_left[dist].push_back(i);
            }
        }
    }

    vector<bool> is_dead(n, false);
    int alive_count = n;
    
    int cur = 0;      
    int min_cur = 0;  
    int max_cur = 0;  

    for (int i = 0; i < k; ++i) {
        if (s[i] == 'L') {
            cur--;
        } else {
            cur++;
        }

        
        if (cur < min_cur) {
            min_cur = cur;
            int dist = -min_cur; 
            
            
            if (dist <= k) {
                for (int robot_idx : die_left[dist]) {
                    if (!is_dead[robot_idx]) {
                        is_dead[robot_idx] = true;
                        alive_count--;
                    }
                }
            }
        } 
        
        else if (cur > max_cur) {
            max_cur = cur;
            int dist = max_cur;
            
            if (dist <= k) {
                for (int robot_idx : die_right[dist]) {
                    if (!is_dead[robot_idx]) {
                        is_dead[robot_idx] = true;
                        alive_count--;
                    }
                }
            }
        }
        
        cout << alive_count << (i == k - 1 ? "" : " ");
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