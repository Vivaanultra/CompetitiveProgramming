#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p;
vector<int> q;
string path;
bool found_sol;

// Check if the last 5 elements of q form a bad sequence
bool is_bad() {
    int sz = q.size();
    if (sz < 5) return false;
    
    // Check for strictly increasing
    bool inc = true;
    for (int k = 0; k < 4; ++k) {
        if (q[sz - 5 + k] >= q[sz - 5 + k + 1]) {
            inc = false; 
            break;
        }
    }
    if (inc) return true;
    
    // Check for strictly decreasing
    bool dec = true;
    for (int k = 0; k < 4; ++k) {
        if (q[sz - 5 + k] <= q[sz - 5 + k + 1]) {
            dec = false; 
            break;
        }
    }
    if (dec) return true;
    
    return false;
}

// Calculate the risk of the current state (length of monotonic suffix)
// We only care up to length 5.
int get_risk() {
    int sz = q.size();
    if (sz == 0) return 0;
    
    int inc = 1;
    for (int i = sz - 2; i >= max(0, sz - 5); --i) {
        if (q[i] < q[i+1]) inc++;
        else break;
    }
    
    int dec = 1;
    for (int i = sz - 2; i >= max(0, sz - 5); --i) {
        if (q[i] > q[i+1]) dec++;
        else break;
    }
    return max(inc, dec);
}

void dfs(int l, int r) {
    if (found_sol) return;
    if (l > r) {
        found_sol = true;
        cout << path << "\n";
        return;
    }

    struct Option {
        char type;
        int val;
        int risk;
    };
    vector<Option> opts;

    // Try picking Left
    q.push_back(p[l]);
    if (!is_bad()) {
        opts.push_back({'L', p[l], get_risk()});
    }
    q.pop_back();

    // Try picking Right (if distinct)
    if (l != r) {
        q.push_back(p[r]);
        if (!is_bad()) {
            opts.push_back({'R', p[r], get_risk()});
        }
        q.pop_back();
    }

    // Sort options to try the one with lower risk first
    sort(opts.begin(), opts.end(), [](const Option& a, const Option& b) {
        return a.risk < b.risk;
    });

    for (auto& opt : opts) {
        q.push_back(opt.val);
        path.push_back(opt.type);
        
        if (opt.type == 'L') dfs(l + 1, r);
        else dfs(l, r - 1);
        
        if (found_sol) return;
        
        path.pop_back();
        q.pop_back();
    }
}

void solve() {
    cin >> n;
    p.resize(n);
    for (int& x : p) cin >> x;
    
    q.clear();
    path.clear();
    found_sol = false;
    
    dfs(0, n - 1);
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