#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    vector<int> B(N);
    for (int i = 0; i < N; ++i) cin >> B[i];
    
    
    for (int i = 0; i < N - 1; ++i) {
        bool a_increasing = (A[i] < A[i+1]);
        bool b_increasing = (B[i] < B[i+1]);
        
        
        if (a_increasing != b_increasing) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
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