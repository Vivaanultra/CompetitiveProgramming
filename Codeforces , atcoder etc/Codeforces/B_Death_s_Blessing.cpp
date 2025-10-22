// I am a fucking idiot and did this problem with DP in the first go. got MLE on case 3! forgot its not an atocoder dp contest.
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long sum_a = 0;
    long long sum_b = 0;
    long long max_b = 0;
    
    for (int i = 0; i < n; ++i) {
        long long health;
        cin >> health;
        sum_a += health;
    }
    
    for (int i = 0; i < n; ++i) {
        long long blessing;
        cin >> blessing;
        sum_b += blessing;
        if (blessing > max_b) {
            max_b = blessing;
        }
    }
    
    cout << sum_a + sum_b - max_b << endl;
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