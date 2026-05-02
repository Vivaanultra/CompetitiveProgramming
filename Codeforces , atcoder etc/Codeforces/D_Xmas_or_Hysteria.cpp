#include <bits/stdc++.h>

using namespace std;

struct Elf {
    long long a;
    int id;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Elf> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i].a;
        e[i].id = i + 1;
    }

    sort(e.begin(), e.end(), [](const Elf& a, const Elf& b) {
        return a.a < b.a;
    });

    if (m == 0) {
        if (n < 3) {
            cout << -1 << "\n";
            return;
        }

        long long gap = e[n - 1].a - e[n - 2].a;
        long long current_sum = 0;
        int k = -1;

        for (int i = n - 3; i >= 0; --i) {
            current_sum += e[i].a;
            if (current_sum >= gap) {
                k = i;
                break;
            }
        }

        if (k == -1) {
            cout << -1 << "\n";
            return;
        }

        vector<pair<int, int>> moves;
        for (int i = 0; i < k; ++i) {
            moves.push_back({e[i].id, e[i + 1].id});
        }
        for (int i = k; i <= n - 3; ++i) {
            moves.push_back({e[i].id, e[n - 1].id});
        }
        moves.push_back({e[n - 1].id, e[n - 2].id});

        cout << moves.size() << "\n";
        for (const auto& p : moves) {
            cout << p.first << " " << p.second << "\n";
        }
        return;
    }

    if (m == 1) {
        cout << n - 1 << "\n";
        for (int i = 0; i < n - 1; ++i) {
            cout << e[i].id << " " << e[i + 1].id << "\n";
        }
        return;
    }

    if (2 * m > n) {
        cout << -1 << "\n";
        return;
    }

    priority_queue<pair<long long, int>> pq;
    vector<pair<int, int>> moves;
    vector<pair<int, int>> s_attacks;

    for (int i = 0; i < m; ++i) {
        int s_idx = n - m + i;
        int f_idx = i;

        long long hp = e[s_idx].a - e[f_idx].a;
        if (hp <= 0) {
            cout << -1 << "\n";
            return;
        }
        pq.push({hp, e[s_idx].id});
        s_attacks.push_back({e[s_idx].id, e[f_idx].id});
    }

    for (int i = n - m - 1; i >= m; --i) {
        long long waste_val = e[i].a;
        if (pq.empty()) {
            cout << -1 << "\n";
            return;
        }

        pair<long long, int> top = pq.top();
        pq.pop();

        if (top.first - waste_val <= 0) {
            cout << -1 << "\n";
            return;
        }

        top.first -= waste_val;
        moves.push_back({e[i].id, top.second});
        pq.push(top);
    }

    for (const auto& p : s_attacks) {
        moves.push_back(p);
    }

    cout << moves.size() << "\n";
    for (const auto& p : moves) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}