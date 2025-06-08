#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = 0;
    if (m * a <= b)
    {
        ans = n * a;
    }
    else
    {
        ans = (n / m) * b + min((n % m) * a, b);
    }
    cout << ans << endl;
    return 0;
}