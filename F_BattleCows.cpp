#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> tree; 
vector<long long> initial_a; 


void update(int idx, long long val) {
    int tree_idx = (1 << n) + idx; 
    tree[tree_idx] = val;
    tree_idx /= 2;
    
    while (tree_idx > 0) {
        tree[tree_idx] = tree[2 * tree_idx] ^ tree[2 * tree_idx + 1];
        tree_idx /= 2;
    }
}


int solve_query(int idx) {
    int ans = 0;
    int curr = (1 << n) + idx; 
    
    
    for (int layer = 0; layer < n; ++layer) {
        bool is_left_child = (curr % 2 == 0);
        int sibling = is_left_child ? curr + 1 : curr - 1;
        
        long long my_val = tree[curr];
        long long op_val = tree[sibling];
        
        bool i_win = false;
        
        
        if (is_left_child) {
            
            if (my_val >= op_val) i_win = true;
        } else {
            
            if (my_val > op_val) i_win = true;
        }
        
        if (!i_win) {
            
            
            
            ans += (1 << layer);
        }
        
        
        curr /= 2;
    }
    return ans;
}

void solve() {
    int q;
    cin >> n >> q;
    int num_cows = 1 << n; 
    
    initial_a.resize(num_cows);
    
    tree.assign(2 * num_cows, 0);
    
    for (int i = 0; i < num_cows; ++i) {
        cin >> initial_a[i];
        tree[num_cows + i] = initial_a[i]; 
    }
    
    
    for (int i = num_cows - 1; i > 0; --i) {
        tree[i] = tree[2 * i] ^ tree[2 * i + 1];
    }
    
    while (q--) {
        int idx;
        long long val;
        cin >> idx >> val;
        --idx; 
        
        long long original_val = initial_a[idx];
        
        
        update(idx, val);
        
        
        cout << solve_query(idx) << endl;
        
        
        update(idx, original_val);
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