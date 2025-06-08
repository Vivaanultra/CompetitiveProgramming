#include <bits/stdc++.h>
using namespace std;

long long count_pairs(long long k) {
    if (k <= 1) {
        return 0;
    }
    return k * (k - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m;

    long long q_min = n / m;
    long long r_min = n % m;
    long long k_min = r_min * count_pairs(q_min + 1) + (m - r_min) * count_pairs(q_min);

    long long large_team_size_max = n - (m - 1);
    long long k_max = count_pairs(large_team_size_max);

    cout << k_min << " " << k_max << endl;

    return 0;
}