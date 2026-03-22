#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int tasks , show , mins;
        cin >> tasks >> show >> mins;
        vector<int> v;
        v.push_back(0);
        for(int i = 0; i < tasks; i++)
        {
            int a , b;
            cin >> a >> b;
            v.push_back(a);
            v.push_back(b);
        }
        v.push_back(mins);
        bool flag = false;
        for(int i = 0; i < v.size(); i+=2)
        {
            if(v[i + 1] - v[i] >= show)
            {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}