#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        int num_corners = 1 << n;
        vector<int> weights(num_corners);
        for (int i = 0; i < num_corners; ++i) {
            cin >> weights[i];
        }

        vector<int> potencies(num_corners, 0);
        for (int i = 0; i < num_corners; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbor = i ^ (1 << j);
                potencies[i] += weights[neighbor];
            }
        }

        int max_sum = 0;
        for (int i = 0; i < num_corners; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbor = i ^ (1 << j);
                max_sum = max(max_sum, potencies[i] + potencies[neighbor]);
            }
        }
        
        cout << max_sum << "\n";
    }

    return 0;
}