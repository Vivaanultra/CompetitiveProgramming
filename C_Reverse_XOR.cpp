#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

struct DSU {
    vector<int> parent;
    vector<int> val; 
    vector<int> known; 
    bool possible;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        val.assign(n, 0);
        known.assign(n, -1);
        possible = true;
    }

    pair<int, int> find(int i) {
        if (parent[i] == i) return {i, 0};
        pair<int, int> root = find(parent[i]);
        parent[i] = root.first;
        val[i] ^= root.second;
        return {parent[i], val[i]};
    }

    void add_rel(int i, int j, int x) {
        if (!possible) return;
        pair<int, int> ri = find(i);
        pair<int, int> rj = find(j);
        int u = ri.first;
        int v = rj.first;
        int xr = x ^ ri.second ^ rj.second;
        
        if (u != v) {
            parent[u] = v;
            val[u] = xr;
            if (known[u] != -1) {
                if (known[v] != -1) {
                    if ((known[u] ^ xr) != known[v]) possible = false;
                } else {
                    known[v] = known[u] ^ xr;
                }
            }
        } else {
            if (xr != 0) possible = false;
        }
    }

    void set_val(int i, int x) {
        if (!possible) return;
        pair<int, int> ri = find(i);
        int u = ri.first;
        int cur = x ^ ri.second;
        if (known[u] != -1) {
            if (known[u] != cur) possible = false;
        } else {
            known[u] = cur;
        }
    }
};

void solve() {
    ull n;
    if (!(cin >> n)) return;

    if (n == 0) {
        cout << "YES\n";
        return;
    }

    int trail = 0;
    ull temp = n;
    while ((temp & 1) == 0) {
        trail++;
        temp >>= 1;
    }

    int len = 0;
    temp = n;
    while (temp > 0) {
        len++;
        temp >>= 1;
    }

    if (trail > 0) {
        int L = len + trail;
        bool ok = true;
        for (int i = 0; i < L / 2; ++i) {
            int b1 = (i < len) ? ((n >> i) & 1) : 0;
            int b2 = ((L - 1 - i) < len) ? ((n >> (L - 1 - i)) & 1) : 0;
            if (b1 != b2) {
                ok = false;
                break;
            }
        }
        if (L % 2 == 1) {
            int mid = L / 2;
            int b = (mid < len) ? ((n >> mid) & 1) : 0;
            if (b == 1) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    } else {
        bool found = false;
        for (int k = 1; k < len; ++k) {
            int Ly = len - k;
            if (Ly <= 0) continue;
            DSU dsu(Ly);
            
            for (int i = 0; i < len; ++i) {
                int bit_n = (n >> i) & 1;
                int p1 = i - k;
                int p2 = Ly - 1 - i;
                bool has_p1 = (p1 >= 0 && p1 < Ly);
                bool has_p2 = (p2 >= 0 && p2 < Ly);
                
                if (has_p1 && has_p2) {
                    dsu.add_rel(p1, p2, bit_n);
                } else if (has_p1) {
                    dsu.set_val(p1, bit_n);
                } else if (has_p2) {
                    dsu.set_val(p2, bit_n);
                } else {
                    if (bit_n != 0) dsu.possible = false;
                }
            }
            dsu.set_val(0, 1);
            dsu.set_val(Ly - 1, 1);
            
            if (dsu.possible) {
                found = true;
                break;
            }
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}