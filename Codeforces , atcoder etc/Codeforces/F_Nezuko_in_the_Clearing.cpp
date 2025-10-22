#include <iostream>

using namespace std;

bool check(long long h, long long d, long long rests) {
    long long num_blocks = rests + 1;
    long long q = d / num_blocks;
    long long rem = d % num_blocks;

    __int128_t cost = (__int128_t)rem * (q + 1) * (q + 2) / 2 + 
                      (__int128_t)(num_blocks - rem) * q * (q + 1) / 2;
    
    __int128_t health_pool = h + rests;

    // The health pool must be strictly greater than the cost.
    return cost < health_pool;
}

void solve() {
    long long h, d;
    cin >> h >> d;

    if ((__int128_t)h > (__int128_t)d * (d + 1) / 2) {
        cout << d << "\n";
        return;
    }

    long long low = 0, high = 2e9; 
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(h, d, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << d + ans << "\n";
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