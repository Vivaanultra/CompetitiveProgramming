#include <bits/stdc++.h>
using namespace std;

const int N = 7;
bool vis[9][9];
int p[48];
int ans = 0;

void solve(int r, int c, int idx) {
    if (r == 7 && c == 1) {
        if (idx == 48) ans++;
        return;
    }
    if (idx == 48) return;

    if (vis[r][c-1] && vis[r][c+1] && !vis[r-1][c] && !vis[r+1][c]) return;
    if (vis[r-1][c] && vis[r+1][c] && !vis[r][c-1] && !vis[r][c+1]) return;

    vis[r][c] = true;

    if (p[idx] < 4) {
        int nr = r, nc = c;
        if (p[idx] == 0) nr--;
        else if (p[idx] == 1) nc++;
        else if (p[idx] == 2) nr++;
        else nc--;

        if (!vis[nr][nc]) solve(nr, nc, idx + 1);
    } else {
        if (!vis[r-1][c]) solve(r - 1, c, idx + 1);
        if (!vis[r][c+1]) solve(r, c + 1, idx + 1);
        if (!vis[r+1][c]) solve(r + 1, c, idx + 1);
        if (!vis[r][c-1]) solve(r, c - 1, idx + 1);
    }

    vis[r][c] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < 48; i++) {
        if (s[i] == 'U') p[i] = 0;
        else if (s[i] == 'R') p[i] = 1;
        else if (s[i] == 'D') p[i] = 2;
        else if (s[i] == 'L') p[i] = 3;
        else p[i] = 4;
    }

    for (int i = 0; i < 9; i++) {
        vis[i][0] = vis[i][8] = vis[0][i] = vis[8][i] = true;
    }

    solve(1, 1, 0);
    cout << ans << "\n";

    return 0;
}