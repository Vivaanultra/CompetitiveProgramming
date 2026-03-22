#include<bits/stdc++.h>
using namespace std;


int get_val(const string& S, int idx, int N) {
    return S[(idx % N + N) % N] - '0';
}




vector<int> get_best_path(const string& S, int N, int L, int R, int step, int depth) {
    if (depth == 0) return {};

    int target = (step % 2 != 0) ? 1 : 0; 
    
    
    int idx_left = (L - 1 + N) % N;
    int val_left = S[idx_left] - '0';
    int match_left = (val_left == target);
    
    
    int idx_right = (R + 1) % N;
    int val_right = S[idx_right] - '0';
    int match_right = (val_right == target);

    
    vector<int> path_from_left = get_best_path(S, N, idx_left, R, step + 1, depth - 1);
    vector<int> path_from_right = get_best_path(S, N, L, idx_right, step + 1, depth - 1);

    
    path_from_left.insert(path_from_left.begin(), match_left);
    path_from_right.insert(path_from_right.begin(), match_right);

    
    if (path_from_left > path_from_right) return path_from_left;
    else return path_from_right;
}

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    
    K--;

    
    if (S[K] == '0') {
        cout << -1 << endl;
        return;
    }

    vector<int> result;
    result.push_back(K + 1); 

    int L = K;
    int R = K;
    long long score = 1;

    for (int step = 2; step <= N; ++step) {
        int idx_left = (L - 1 + N) % N;
        int idx_right = (R + 1) % N;
        int val_left = S[idx_left] - '0';
        int val_right = S[idx_right] - '0';

        bool pick_left = false;
        bool is_even_step = (step % 2 == 0);

        
        if (is_even_step && score == 1) {
            if (val_left == 1 && val_right == 1) {
                
                cout << -1 << endl;
                return;
            }
            if (val_left == 0 && val_right == 1) {
                pick_left = true;
            } else if (val_left == 1 && val_right == 0) {
                pick_left = false;
            } else {
                
                
                
                if (get_best_path(S, N, idx_left, R, step + 1, 5) >= 
                    get_best_path(S, N, L, idx_right, step + 1, 5)) {
                    pick_left = true;
                } else {
                    pick_left = false;
                }
            }
        } 
        
        else {
            
            
            
            
            vector<int> q_left = get_best_path(S, N, idx_left, R, step + 1, 5);
            int target = is_even_step ? 0 : 1;
            q_left.insert(q_left.begin(), (val_left == target));

            
            vector<int> q_right = get_best_path(S, N, L, idx_right, step + 1, 5);
            q_right.insert(q_right.begin(), (val_right == target));

            if (q_left >= q_right) pick_left = true;
            else pick_left = false;
        }

        
        if (pick_left) {
            L = idx_left;
            result.push_back(L + 1);
            if (is_even_step) score -= val_left;
            else score += val_left;
        } else {
            R = idx_right;
            result.push_back(R + 1);
            if (is_even_step) score -= val_right;
            else score += val_right;
        }
    }

    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}