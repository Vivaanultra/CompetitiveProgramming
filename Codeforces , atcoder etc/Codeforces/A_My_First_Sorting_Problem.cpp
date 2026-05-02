#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        cout << min(n , p) << " " << max(n , p) << endl;
    }
    return 0;
}