#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // A min-priority queue automatically keeps the smallest element at the top.
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        pq.push(val);
    }

    // Repeat the operation until only one number is left.
    while (pq.size() > 1) {
        // Get the two smallest numbers.
        long long smallest1 = pq.top();
        pq.pop();
        long long smallest2 = pq.top();
        pq.pop();

        // Combine them and put the result back.
        long long average = (smallest1 + smallest2) / 2;
        pq.push(average);
    }

    // The last remaining number is the answer.
    cout << pq.top() << endl;
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