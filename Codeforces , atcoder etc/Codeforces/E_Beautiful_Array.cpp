#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Group elements by residue modulo k and compute quotients
        map<long long, vector<long long>> group;
        for(int i = 0; i < n; i++) {
            long long r = a[i] % k;
            long long q = a[i] / k;
            group[r].push_back(q);
        }
        
        // Check if it's possible to make the array beautiful
        int odd_count = 0;
        for(auto& p : group) {
            if(p.second.size() % 2 == 1) odd_count++;
        }
        bool possible = (n % 2 == 0) ? (odd_count == 0) : (odd_count == 1);
        if(!possible) {
            cout << -1 << endl;
            continue;
        }
        
        // Compute the minimum number of operations
        long long total = 0;
        for(auto& p : group) {
            vector<long long>& vec = p.second;
            sort(vec.begin(), vec.end());
            int s = vec.size();
            if(s % 2 == 0) {
                // Even-sized group: pair adjacent elements
                int m = s / 2;
                for(int i = 0; i < m; i++) {
                    total += vec[2 * i + 1] - vec[2 * i];
                }
            } else {
                // Odd-sized group: sum smallest m differences
                int m = (s - 1) / 2;
                vector<long long> d(s - 1);
                for(int i = 0; i < s - 1; i++) {
                    d[i] = vec[i + 1] - vec[i];
                }
                sort(d.begin(), d.end());
                for(int i = 0; i < m; i++) {
                    total += d[i];
                }
            }
        }
        cout << total << endl;
    }
    return 0;
}