#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin >> n >> t;
    int a[n];
    int sum = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        q.push(x);
        while(sum > t)
        {
            sum -= q.front();
            q.pop();
        }
        a[i] = q.size();
    }
   int ans = *max_element(a, a + n);
   cout << ans;
    

}