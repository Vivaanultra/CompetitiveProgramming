#include <bits/stdc++.h>
using namespace std;

namespace solution {
    bool hasMultipleTests = true;
 
    int n;
    vector<int> a;
 
    void preprocess() {
 
    }
 
    void input(int testcase) {
        cin >> n;
        a.clear();
        a.resize(n);
        for (auto &z: a) cin >> z;
    }
 
    void solve(int testcase) {
        sort(a.begin(), a.end());
 
        int l = 0, ans = n - 2;
        for (int r = 2; r < n; r++) {
            while (r - l >= 2 && a[l] + a[l+1] <= a[r]) l++;
            ans = min(ans, n - (r - l + 1));
        }
 
        cout << ans << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    solution::preprocess();
 
    int t = 1;
    if (solution::hasMultipleTests) cin >> t;
 
    for (int testcase=1; testcase<=t; testcase++) {
        solution::input(testcase);
        solution::solve(testcase);
    }
 
    return 0;
}