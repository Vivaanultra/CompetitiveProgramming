
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    vector<long long> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    // Check if the string 's' contains any 'B' machines.
    bool has_b = false;
    for (char c : s) {
        if (c == 'B') {
            has_b = true;
            break;
        }
    }

    vector<long long> answers;
    for (long long a : queries) {
        if (!has_b) {
            // If there are no 'B' machines, it's all 'A's.
            // It will take exactly 'a' steps to reach 0.
            answers.push_back(a);
        } else {
            // If there is at least one 'B', the value 'a' will decrease
            // at least logarithmically. The total steps will be at most
            // O(n * log(a)), which is fast enough to simulate directly.
            
            long long current_a = a;
            long long steps = 0;
            int machine_idx = 0; // Start at machine 1 (0-indexed)

            while (current_a > 0) {
                steps++;
                
                // 1. Apply the machine's operation
                if (s[machine_idx] == 'A') {
                    current_a--;
                } else { // s[machine_idx] == 'B'
                    current_a /= 2; // Equivalent to floor(current_a / 2)
                }

                // 2. Move to the next machine
                machine_idx = (machine_idx + 1) % n;
            }
            answers.push_back(steps);
        }
    }

    // Output all answers for this test case
    for (int i = 0; i < answers.size(); ++i) {
        cout << answers[i] << (i == answers.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize C++ IO operations
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}