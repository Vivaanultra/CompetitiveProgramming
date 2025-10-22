#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // A priority queue to always have the most sociable person at the top.
    // It stores pairs of {sociability, person_index}.
    priority_queue<pair<int, int>> pq;
    
    for (int i = 1; i <= n; ++i) {
        int sociability;
        cin >> sociability;
        if (sociability > 0) {
            pq.push({sociability, i});
        }
    }

    vector<pair<int, int>> talks;

    // Keep pairing the top two as long as there are at least two people.
    while (pq.size() >= 2) {
        // Get the two most sociable people.
        pair<int, int> p1 = pq.top();
        pq.pop();
        pair<int, int> p2 = pq.top();
        pq.pop();
        
        // Record their talk.
        talks.push_back({p1.second, p2.second});
        
        // Decrease their sociability.
        p1.first--;
        p2.first--;
        
        // If they can still talk, put them back in the queue.
        if (p1.first > 0) {
            pq.push(p1);
        }
        if (p2.first > 0) {
            pq.push(p2);
        }
    }

    cout << talks.size() << endl;
    for (const auto& talk : talks) {
        cout << talk.first << " " << talk.second << endl;
    }
}

int main() {
    // It is currently Sunday, 12:04 AM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}