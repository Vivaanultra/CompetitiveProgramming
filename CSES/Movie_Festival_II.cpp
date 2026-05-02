#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mov , num;
    cin >> mov >> num;
    vector<pair<int,int>> a(mov);
    for(int i = 0; i < mov; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    multiset<int> s;
    int temp = num;
    while(temp--)
    {
        s.insert(0);
    }
    for(int i = 0; i < mov; i++)
    {   
        auto it = s.upper_bound(a[i].second);
        if(it == s.begin())
        {
            continue;
        }
        ;
        it--;
        s.erase(it);
        s.insert(a[i].first);
        ans++;
    }
    cout << ans;
}