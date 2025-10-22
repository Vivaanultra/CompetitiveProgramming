#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    vector<long long> solutions;
    long long power_of_10 = 10;

    for (int k = 1; k <= 18; ++k) {
        long long divisor = 1 + power_of_10;
        if (divisor > n) {
            break;
        }

        if (n % divisor == 0) {
            solutions.push_back(n / divisor);
        }

        if (power_of_10 > n / 10) {
            break;
        }
        power_of_10 *= 10;
    }

    sort(solutions.begin(), solutions.end());

    cout << solutions.size();
    for (long long x : solutions) {
        cout << " " << x;
    }
    cout << "\n";
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