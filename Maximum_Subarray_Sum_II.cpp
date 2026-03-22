#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int a, b;
    cin >> n >> a >> b;

    vector<long long> p(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        p[i] = p[i - 1] + x;
    }

    multiset<long long> s;
    long long max_sum = -4e18; 

    for (int i = a; i <= n; i++)
    {
        if (i > b)
        {
            s.erase(s.find(p[i - b - 1]));
        }
        
        s.insert(p[i - a]);
        
        max_sum = max(max_sum, p[i] - *s.begin());
    }

    cout << max_sum << endl;

    return 0;
}