#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Valid large value that fits in |ai| <= 10^18. 
// 1e18 is sufficient to break any sum since k <= 10^12 and other numbers are small.
const ll INF_VAL = 1e18; 

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Check existing segments
    // We simulate the array where all '0's are -INF_VAL
    ll max_so_far = -INF_VAL;
    ll current_max = -INF_VAL;

    // We must handle the case where the whole array is empty spots correctly
    // Initialize max_so_far to a very small number, but if we encounter real numbers, use them.
    
    // To properly simulate Kadane's with -INF "walls":
    for (int i = 0; i < n; i++) {
        ll val = (s[i] == '0') ? -INF_VAL : a[i];
        
        if (current_max < 0) {
            current_max = val;
        } else {
            current_max += val;
        }
        
        // If we just added -INF, current_max becomes huge negative. 
        // We need to cap it so it doesn't overflow if we keep adding.
        if (current_max < -INF_VAL) current_max = -INF_VAL;
        
        max_so_far = max(max_so_far, current_max);
    }

    // If max_so_far is still -INF (e.g. all zeros), effectively the max sum is -INF (or undefined/empty). 
    // But logically, if we haven't built anything > k, we are fine to proceed.
    
    if (max_so_far > k) {
        cout << "NO" << endl;
        return;
    }

    if (max_so_far == k) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cout << -INF_VAL << " ";
            else cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    // Find a zero to use as a bridge
    int zero_idx = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            zero_idx = i;
            break; 
        }
    }

    if (zero_idx == -1) {
        // No zeros to modify, and max_so_far < k
        cout << "NO" << endl;
        return;
    }

    // Step 2: Construct the bridge at zero_idx
    // Calculate L: Max suffix sum of the left fixed block
    ll L = 0;
    ll current_suffix = 0;
    for (int i = zero_idx - 1; i >= 0; i--) {
        if (s[i] == '0') break; 
        current_suffix += a[i];
        L = max(L, current_suffix);
    }

    // Calculate R: Max prefix sum of the right fixed block
    ll R = 0;
    ll current_prefix = 0;
    for (int i = zero_idx + 1; i < n; i++) {
        if (s[i] == '0') break; 
        current_prefix += a[i];
        R = max(R, current_prefix);
    }

    // We set the bridge value such that L + val + R = k
    a[zero_idx] = k - L - R;
    s[zero_idx] = '1'; 

    // Final Output
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cout << -INF_VAL << " ";
        else cout << a[i] << " ";
    }
    cout << endl;
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