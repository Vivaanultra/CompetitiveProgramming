#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M, K, L;
    if (!(cin >> N >> M >> K >> L)) return;

    vector<int> S(K);
    for (int i = 0; i < K; ++i) cin >> S[i];

    vector<int> D(L);
    for (int i = 0; i < L; ++i) cin >> D[i];

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    bool valid_base = true;
    for (int x : S) {
        if (dist[x] == -1) {
            valid_base = false;
        }
    }

    sort(S.begin(), S.end(), [&](int a, int b) {
        return dist[a] < dist[b];
    });

    for (int i = 1; i < K; ++i) {
        if (dist[S[i]] == dist[S[i - 1]]) {
            valid_base = false;
        }
    }

    vector<bool> fwd(N + 1, false);
    vector<bool> bwd(N + 1, false);

    if (valid_base) {
        int curr_start = 1;

        for (int i = 0; i < K; ++i) {
            int curr_end = S[i];

            queue<int> fq;
            fq.push(curr_start);
            fwd[curr_start] = true;
            while (!fq.empty()) {
                int u = fq.front();
                fq.pop();
                if (dist[u] == dist[curr_end]) continue;
                for (int v : adj[u]) {
                    if (dist[v] == dist[u] + 1 && dist[v] <= dist[curr_end]) {
                        if (!fwd[v]) {
                            fwd[v] = true;
                            fq.push(v);
                        }
                    }
                }
            }

            if (!fwd[curr_end]) {
                valid_base = false;
                break;
            }

            queue<int> bq;
            bq.push(curr_end);
            bwd[curr_end] = true;
            while (!bq.empty()) {
                int u = bq.front();
                bq.pop();
                if (dist[u] == dist[curr_start]) continue;
                for (int v : adj[u]) {
                    if (dist[v] == dist[u] - 1 && dist[v] >= dist[curr_start]) {
                        if (!bwd[v]) {
                            bwd[v] = true;
                            bq.push(v);
                        }
                    }
                }
            }
            curr_start = curr_end;
        }

        if (valid_base) {
            queue<int> fq;
            fq.push(curr_start);
            fwd[curr_start] = true;
            while (!fq.empty()) {
                int u = fq.front();
                fq.pop();
                for (int v : adj[u]) {
                    if (dist[v] == dist[u] + 1) {
                        if (!fwd[v]) {
                            fwd[v] = true;
                            fq.push(v);
                        }
                    }
                }
            }

            queue<int> bq;
            bool any_d = false;
            for (int x : D) {
                if (dist[x] != -1 && dist[x] >= dist[curr_start] && fwd[x]) {
                    bq.push(x);
                    bwd[x] = true;
                    any_d = true;
                }
            }

            if (!any_d) {
                valid_base = false;
            } else {
                while (!bq.empty()) {
                    int u = bq.front();
                    bq.pop();
                    if (dist[u] == dist[curr_start]) continue;
                    for (int v : adj[u]) {
                        if (dist[v] == dist[u] - 1 && dist[v] >= dist[curr_start]) {
                            if (!bwd[v]) {
                                bwd[v] = true;
                                bq.push(v);
                            }
                        }
                    }
                }
            }
        }
    }

    vector<bool> check_dist(N + 1, false);
    set<int> S_set;
    for (int x : S) {
        if (dist[x] != -1) check_dist[dist[x]] = true;
        S_set.insert(x);
    }

    string ans = "";
    for (int i = 2; i <= N; ++i) {
        if (!valid_base) {
            ans += '0';
        } else if (S_set.count(i)) {
            ans += '1';
        } else if (dist[i] != -1 && fwd[i] && bwd[i] && !check_dist[dist[i]]) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << "\n";
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