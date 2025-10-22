#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Day 1 initialization
    bool C = (a[0] == 1 || a[0] == 3); // possible contest
    bool S = (a[0] == 2 || a[0] == 3); // possible sport
    int rest_days = (C || S) ? 0 : 1;

    for (int i = 1; i < n; i++) {
        bool canC = (a[i] == 1 || a[i] == 3);
        bool canS = (a[i] == 2 || a[i] == 3);

        bool prevC = C, prevS = S;
        bool prevRest = !(prevC || prevS);

        C = canC && (prevS || prevRest);  // contest today if sport/rest yesterday
        S = canS && (prevC || prevRest);  // sport today if contest/rest yesterday

        if (!C && !S) rest_days++;        // forced rest today
    }

    cout << rest_days << "\n";
    return 0;
}
