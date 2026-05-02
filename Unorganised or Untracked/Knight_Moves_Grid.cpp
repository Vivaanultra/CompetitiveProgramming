#include <bits/stdc++.h>
using namespace std;

// Direction arrays for Knight moves
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // Grid to store distances. Initialize with -1 (unvisited)
    // Using vector of vectors for dynamic sizing based on input n
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // Start BFS from top-left (0,0)
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check boundaries and if already visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // Print the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}