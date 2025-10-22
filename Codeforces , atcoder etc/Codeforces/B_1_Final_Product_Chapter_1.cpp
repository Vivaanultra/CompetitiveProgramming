#include <bits/stdc++.h>
using namespace std;

void solve(int case_num) {
    int n;
    long long a, b;
    cin >> n >> a >> b;

    long long m1 = 0;
    for (long long i = a; i >= 1; --i) {
        if (b % i == 0) {
            m1 = i;
            break;
        }
    }

    long long m2 = b / m1;

    vector<long long> result;
    result.push_back(m1);
    for (int i = 0; i < n - 1; ++i) {
        result.push_back(1);
    }
    result.push_back(m2);
    for (int i = 0; i < n - 1; ++i) {
        result.push_back(1);
    }

    cout << "Case #" << case_num << ": ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
}