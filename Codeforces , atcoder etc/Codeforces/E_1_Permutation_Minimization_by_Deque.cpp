#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    if (n == 0) {
        cout << endl;
        return;
    }

    deque<int> dq;
    // The first element always starts the deque.
    dq.push_back(p[0]);

    // For all other elements, apply the greedy "Front First" rule.
    for (int i = 1; i < n; ++i) {
        if (p[i] < dq.front()) {
            dq.push_front(p[i]);
        } else {
            dq.push_back(p[i]);
        }
    }

    // Print the final result.
    for (int i = 0; i < n; ++i) {
        cout << dq[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // It is currently Sunday, 12:11 AM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}