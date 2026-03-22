#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sz , k;
    cin >> sz >> k;
    vector<int> v(sz);
    for(int i = 0; i < sz; i++)
    {
        cin >> v[i];
    }
    map<int, vector<pair<int,int>>> mp;
    for(int i = 0; i < sz - 1; i++)
    {
        for(int j = i + 1; j < sz; j++)
        {
            if(mp.find(k - v[i] - v[j]) == mp.end())
            {
                mp[v[i] + v[j]].push_back({i+1,j+1});
            }
            else
            {
                for(auto x : mp[k - v[i] - v[j]])
                {
                    if(x.first != i+1 && x.first != j+1 && x.second != i+1 && x.second != j+1)
                    {
                        cout << x.first << " " << x.second << " " << i+1 << " " << j+1 << endl;
                        return 0;
                    }
                }
                mp[v[i] + v[j]].push_back({i+1,j+1});
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;

    
}