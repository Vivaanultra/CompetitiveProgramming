#include <iostream>
#include <string>
#include <stdexcept> // Required for std::out_of_range
// #include <algorithm> // Was included but not used
using namespace std;

long long construct_y(int x, int k) {
    string s = to_string(x);
    string y_str = "";
    for (int i = 0; i < k; ++i) {
        y_str += s;
    }
    try {
        return stoll(y_str);
    } catch (const std::out_of_range& oor) {
        return -1; 
    }
}

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, k;
        cin >> x >> k;

        // Simplified logic:
        // If x > 1 and k > 1, y is mathematically x * (1 + 10^L + ... + 10^((k-1)L)).
        // Since x > 1 and (1 + ... > 1), y is composite.
        if (x > 1 && k > 1) {
            cout << "NO" << endl;
        } else {
            // Handles cases: x == 1 (any k) or k == 1 (any x)
            long long y = construct_y(x, k);
            if (y == -1) { // Overflow or invalid construction (e.g. k=0 if allowed by constraints)
                cout << "NO" << endl;
            } else if (is_prime(y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
