#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
    {
        cin >> x;
    }
    stack<pair<int,int>> st;
    for(int i = 0; i < n; i++)
    {
        if(st.empty())
        {
            st.push({v[i],i});
            cout << 0 << " ";
        }
        else
        {
            while(!st.empty() && st.top().first >= v[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                cout << 0 << " ";
            }
            else
            {
                cout << st.top().second + 1 << " ";
            }
            st.push({v[i],i});
        }
    }
}