#include <bits/stdc++.h>
using namespace std;

// helper to print __int128
void print_int128(__int128 x) {
    if (x == 0) { 
        cout << '0'; 
        return; 
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        __int128 global_best = -1; // will set on first iteration

        // try concatenation at gap g (1..n-1)
        for (int g = 1; g < n; g++) {
            // build nums after concatenating s[g-1] & s[g]
            vector<__int128> nums;
            nums.reserve(n-1);
            __int128 cur = s[0] - '0';
            for (int i = 1; i < n; i++) {
                if (i == g) {
                    // concatenate
                    cur = cur * 10 + (s[i] - '0');
                } else {
                    nums.push_back(cur);
                    cur = s[i] - '0';
                }
            }
            nums.push_back(cur);

            int M = nums.size();   // should be n-1
            // dp[i] = min total for first i numbers
            vector<__int128> dp(M+1, -1);
            dp[0] = 0;

            for (int i = 1; i <= M; i++) {
                __int128 best = -1;
                __int128 prod = 1;
                // consider last group from k..i-1
                for (int k = i; k >= 1; k--) {
                    prod *= nums[k-1];
                    __int128 candidate = dp[k-1] + prod;
                    if (dp[k-1] < 0) continue;
                    if (best < 0 || candidate < best) {
                        best = candidate;
                    }
                }
                dp[i] = best;
            }

            __int128 this_best = dp[M];
            if (global_best < 0 || this_best < global_best) {
                global_best = this_best;
            }
        }

        print_int128(global_best);
        cout << "\n";
    }
    return 0;
}
