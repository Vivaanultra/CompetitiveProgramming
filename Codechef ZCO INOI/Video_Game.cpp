#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long h;
    cin >> n >> h;

    vector<long long> stacks(n);
    for (int i = 0; i < n; ++i) {
        cin >> stacks[i];
    }

    int crane_pos = 0;
    bool has_box = false;
    int command;

    while (cin >> command && command != 0) {
        if (command == 1) {
            if (crane_pos > 0) {
                crane_pos--;
            }
        } else if (command == 2) {
            if (crane_pos < n - 1) {
                crane_pos++;
            }
        } else if (command == 3) {
            if (!has_box && stacks[crane_pos] > 0) {
                stacks[crane_pos]--;
                has_box = true;
            }
        } else if (command == 4) {
            if (has_box && stacks[crane_pos] < h) {
                stacks[crane_pos]++;
                has_box = false;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << stacks[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}