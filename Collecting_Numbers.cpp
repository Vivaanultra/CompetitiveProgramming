#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<bool> x(n+1,false);
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(x[v[i] - 1] == false)
        {
            x[v[i]] = true;
            ans++;
        }
        else
        {
            x[v[i]] = true;
        }
    }
    
    cout << ans << endl;
    return 0;

}