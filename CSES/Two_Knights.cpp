#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    for (long long k = 1; k <= n; k++) {
        long long total_ways = (k * k) * (k * k - 1) / 2;
        long long attacking_ways = 4 * (k - 1) * (k - 2);
        cout << total_ways - attacking_ways << "\n";
    }

    return 0;
}