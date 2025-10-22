#include <bits/stdc++.h>
using namespace std;

void solve() {
    int Q;
    cin >> Q;

    // A queue of pairs, where each pair is {value, count}
    queue<pair<long long, long long>> cylinder;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            long long x, c;
            cin >> x >> c;
            cylinder.push({x, c});
        } else {
            long long c;
            cin >> c;

            long long current_sum = 0;
            long long balls_to_remove = c;

            // Process blocks from the left until we've removed enough balls
            while (balls_to_remove > 0) {
                pair<long long, long long> front_block = cylinder.front();
                long long value = front_block.first;
                long long count = front_block.second;

                if (balls_to_remove >= count) {
                    // Take the whole block
                    current_sum += value * count;
                    balls_to_remove -= count;
                    cylinder.pop();
                } else {
                    // Take a part of the block
                    current_sum += value * balls_to_remove;
                    // Update the count of the front block
                    cylinder.front().second -= balls_to_remove;
                    balls_to_remove = 0;
                }
            }
            cout << current_sum << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}