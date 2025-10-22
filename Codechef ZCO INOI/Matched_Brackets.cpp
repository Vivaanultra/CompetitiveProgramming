#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int max_depth = 0;
    int max_depth_pos = 0;
    int max_len = 0;
    int max_len_pos = 0;

    int current_depth = 0;
    stack<int> s;

    for (int i = 1; i <= n; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            s.push(i);
            current_depth++;
            if (current_depth > max_depth) {
                max_depth = current_depth;
                max_depth_pos = i;
            }
        } else {
            int start_pos = s.top();
            s.pop();
            
            int current_len = i - start_pos + 1;
            if (current_len > max_len) {
                max_len = current_len;
                max_len_pos = start_pos;
            }
            current_depth--;
        }
    }

    cout << max_depth << " " << max_depth_pos << " " << max_len << " " << max_len_pos << "\n";

    return 0;
}