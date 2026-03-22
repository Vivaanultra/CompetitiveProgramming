#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int max_val = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    // Rotate the array so it starts with the maximum value
    int start_idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == max_val) {
            start_idx = i;
            break;
        }
    }

    vector<int> b;
    b.reserve(n);
    for (int i = 0; i < n; i++) {
        b.push_back(a[(start_idx + i) % n]);
    }
    
    // Append the max_val to the end to ensure the last segment is processed.
    // This simulates the circular connection back to the start.
    b.push_back(max_val);

    long long total_cost = 0;
    int m_count = 0; // Count actual Max occurrences in original array
    
    vector<int> segment;

    // Iterate through the rotated array + sentinel
    for (int i = 0; i < b.size(); i++) {
        int x = b[i];
        
        if (x == max_val) {
            // Only count the max_val if it's part of the original n elements
            if (i < n) m_count++;
            
            if (!segment.empty()) {
                int k = segment.size();
                vector<int> L(k), R(k);
                stack<int> st;

                // Find Nearest Strictly Greater to the Left
                for (int j = 0; j < k; j++) {
                    while (!st.empty() && segment[st.top()] <= segment[j]) {
                        st.pop();
                    }
                    if (st.empty()) L[j] = max_val;
                    else L[j] = segment[st.top()];
                    st.push(j);
                }

                while (!st.empty()) st.pop();

                // Find Nearest Greater or Equal to the Right
                for (int j = k - 1; j >= 0; j--) {
                    while (!st.empty() && segment[st.top()] < segment[j]) {
                        st.pop();
                    }
                    if (st.empty()) R[j] = max_val;
                    else R[j] = segment[st.top()];
                    st.push(j);
                }

                for (int j = 0; j < k; j++) {
                    total_cost += min(L[j], R[j]);
                }
                segment.clear();
            }
        } else {
            segment.push_back(x);
        }
    }

    // Add cost for merging the maximums themselves
    if (m_count > 0) {
        total_cost += (long long)(m_count - 1) * max_val;
    }

    cout << total_cost << "\n";
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