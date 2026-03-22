#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    
    sort(a.begin(), a.end());

    int distinct_odd_freq = 0;
    int distinct_even_freq = 0;
    
    int current_count = 0;
    
    
    for (int i = 0; i < 2 * n; ++i) {
        current_count++;
        
        if (i == 2 * n - 1 || a[i] != a[i + 1]) {
            if (current_count % 2 != 0) {
                distinct_odd_freq++;
            } else {
                distinct_even_freq++;
            }
            current_count = 0;
        }
    }

    
    
    int score = distinct_odd_freq + (2 * distinct_even_freq);

    
    if (distinct_odd_freq == 0) {
        
        if (distinct_even_freq % 2 != n % 2) {
            score -= 2;
        }
    }

    cout << score << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}