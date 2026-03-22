#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int m;
        cin >> n >> m;
        int max = 0;
        vector<int> xmax;
        vector<int> ymax;
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int a;
                cin >> a;
                if(a > max)
                {
                    max = a;
                    xmax.clear();
                    ymax.clear();
                    xmax.push_back(i);
                    ymax.push_back(j);
                }
                else if(a == max)
                {
                    xmax.push_back(i);
                    ymax.push_back(j);
                }
            }
        }
        int j;
        bool flag = false;
        for(int i = 1; i < xmax.size() + 1; i++)
        {
            if(i == xmax.size())
            {
                flag = true;
                break;
            }
            else if(xmax[0] != xmax[i] and ymax[0] != ymax[i])
            {
                j = i;
                break;
            }
        }
        if(flag)
        {
            cout << max - 1 << endl;
            continue;
        }
        int count1 = 0;
        for(int i = 0; i < xmax.size(); i++)
        {
            if(xmax[i] != xmax[0] and ymax[i] != ymax[j])
            {
                count1++;
            }
        }
        int count2 = 0;
        for(int i = 0; i < xmax.size(); i++)
        {
            if(xmax[i] != xmax[j] and ymax[i] != ymax[0])
            {
                count2++;
            }
        }
        if(count1 !=0 and count2 != 0)
        {
            cout << max << endl;
        }
        else
        {
            cout << max - 1 << endl;
        }
    }
        
    return 0;
}