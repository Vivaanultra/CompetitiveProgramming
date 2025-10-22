#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    vector<long long> counts(30, 0);

    for (int i = 0; i < m; ++i) {
        int type;
        long long v;
        cin >> type >> v;

        if (type == 1) {
            counts[v]++;
        } else {
            long long w = v;
            for (int j = 29; j >= 0; --j) {
                if (counts[j] > 0) {
                    long long power_of_2 = 1LL << j;
                    long long needed = w / power_of_2;
                    long long take = min(counts[j], needed);
                    w -= take * power_of_2;
                }
            }

            if (w == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}