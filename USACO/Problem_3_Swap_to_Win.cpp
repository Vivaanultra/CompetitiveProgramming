#include<bits/stdc++.h>
using namespace std;

struct Op {
    int type;
    int arg1, arg2, arg3;
};

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    string t;
    cin >> t;
    
    vector<string> s(N);
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }

    
    vector<vector<int>> grid(N, vector<int>(M));
    vector<vector<int>> pos_in_locs(N, vector<int>(M));
    vector<vector<pair<int, int>>> locs(26);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int c = s[i][j] - 'a';
            grid[i][j] = c;
            locs[c].push_back({i, j});
            pos_in_locs[i][j] = locs[c].size() - 1;
        }
    }

    vector<Op> ops;

    
    auto actual_swap = [&](int r1, int c1, int r2, int c2) {
        if (r1 == r2 && c1 == c2) return;
        
        int v1 = grid[r1][c1];
        int v2 = grid[r2][c2];
        int idx1 = pos_in_locs[r1][c1];
        int idx2 = pos_in_locs[r2][c2];

        locs[v1][idx1] = {r2, c2};
        locs[v2][idx2] = {r1, c1};

        pos_in_locs[r1][c1] = idx2;
        pos_in_locs[r2][c2] = idx1;

        grid[r1][c1] = v2;
        grid[r2][c2] = v1;
    };

    auto op1 = [&](int r, int c1, int c2) {
        actual_swap(r, c1, r, c2);
        ops.push_back({1, r + 1, c1 + 1, c2 + 1});
    };

    auto op2 = [&](int r1, int r2, int c) {
        actual_swap(r1, c, r2, c);
        ops.push_back({2, r1 + 1, r2 + 1, c + 1});
    };

    
    for (int i = 0; i < M; ++i) {
        int tc = t[i] - 'a';
        
        
        if (grid[0][i] == tc) continue;

        bool found = false;

        
        for (int x = 1; x < N; ++x) {
            if (grid[x][i] == tc) {
                op2(0, x, i);
                found = true;
                break;
            }
        }
        if (found) continue;

        
        for (int y = i + 1; y < M; ++y) {
            if (grid[0][y] == tc) {
                op1(0, i, y);
                found = true;
                break;
            }
        }
        if (found) continue;

        
        for (auto p : locs[tc]) {
            int r = p.first;
            int c = p.second;
            
            if (r > 0 && c != i) {
                op1(r, i, c);
                op2(0, r, i);
                found = true;
                break;
            }
        }
    }

    int ElsieNumber = ops.size();
    cout << ElsieNumber << "\n";
    for (const auto& op : ops) {
        if (op.type == 1) {
            cout << "1 " << op.arg1 << " " << op.arg2 << " " << op.arg3 << "\n";
        } else {
            cout << "2 " << op.arg1 << " " << op.arg2 << " " << op.arg3 << "\n";
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}