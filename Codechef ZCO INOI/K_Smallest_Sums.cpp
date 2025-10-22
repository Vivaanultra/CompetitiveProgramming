#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    while (cin >> k) {
        vector<vector<int>> arrays(k, vector<int>(k));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                cin >> arrays[i][j];
            }
            sort(arrays[i].begin(), arrays[i].end());
        }

        vector<int> current_sums = arrays[0];

        for (int i = 1; i < k; ++i) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            
            for (int j = 0; j < k; ++j) {
                pq.push({current_sums[j] + arrays[i][0], 0});
            }

            vector<int> next_sums;
            for (int count = 0; count < k; ++count) {
                pair<int, int> top = pq.top();
                pq.pop();
                
                int sum = top.first;
                int b_index = top.second;
                
                next_sums.push_back(sum);
                
                int a_val = sum - arrays[i][b_index];
                
                if (b_index + 1 < k) {
                    pq.push({a_val + arrays[i][b_index + 1], b_index + 1});
                }
            }
            current_sums = next_sums;
        }

        for (int i = 0; i < k; ++i) {
            cout << current_sums[i] << (i == k - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}