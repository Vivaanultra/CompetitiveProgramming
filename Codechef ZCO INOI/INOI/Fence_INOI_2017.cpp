#include <bits/stdc++.h>
using namespace std;

// Global variables for Subtask 2 (R, C <= 2500)
int R, C, N;
bool grid[2505][2505];     // Stores where the potatoes are
bool visited[2505][2505];  // Stores where we have already looked

// Direction arrays: Up, Down, Left, Right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// --- THIS IS YOUR TASK ---
long long dfs(int r, int c) {
    visited[r][c] = true;
    long long current_fence = 0;

    // Iterate through 4 neighbors
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(!grid[nr][nc])
        {
            current_fence++;
        }
        // 1. CHECK BOUNDARY / UNCULTIVATED
        // Write the "if" statement here to add to fence length
        
        else if(grid[nr][nc] && !visited[nr][nc])
        {
            current_fence += dfs(nr, nc);
        }
        // 2. CHECK RECURSION
        // Write the "if" statement here to continue the search
        
    }
    
    return current_fence;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> R >> C >> N) {
        for(int i = 0; i < N; i++) {
            int r, c;
            cin >> r >> c;
            grid[r][c] = true; // Mark cultivated fields
        }

        long long max_fence = 0;

        // Loop through every cell to find unvisited patches
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    // Start a new patch search
                    long long patch_fence = dfs(i, j);
                    max_fence = max(max_fence, patch_fence);
                }
            }
        }
        cout << max_fence << endl;
    }
    return 0;
}