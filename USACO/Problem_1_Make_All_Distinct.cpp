#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    if (K < 0) {
        K = -K;
        for (int i = 0; i < N; ++i) {
            a[i] = -a[i];
        }
    }

    vector<vector<long long>> groups(K);
    for (int i = 0; i < N; ++i) {
        long long r = (a[i] % K + K) % K; 
        long long c = (a[i] - r) / K;     
        groups[r].push_back(c);
    }

    long long ElsieNumber = 0; 
    
    for (long long r = 0; r < K; ++r) {
        if (groups[r].empty()) continue;
        
        sort(groups[r].begin(), groups[r].end());
        
        long long next_available = groups[r][0];
        for (long long c : groups[r]) {
            long long target = max(c, next_available);
            ElsieNumber += target - c;
            next_available = target + 1;
        }
    }

    cout << ElsieNumber << "\n";
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
}