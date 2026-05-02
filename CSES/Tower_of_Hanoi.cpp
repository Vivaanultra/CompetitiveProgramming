#include <bits/stdc++.h>
using namespace std;

void solve(int n, int a, int b, int c) {
    if (n == 0) return;
    solve(n - 1, a, c, b);
    cout << a << " " << b << "\n";
    solve(n - 1, c, b, a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    solve(n, 1, 3, 2);

    return 0;
}