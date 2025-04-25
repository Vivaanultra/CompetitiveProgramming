#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int a , b;
        cin >> a >> b;
        int g;
        vector<int> vec(a);
        for(int i = 0; i < a; i++)
        {
            cin >> vec[i];
        }
        cin >>  g;
        vec[0] = min(vec[0], g-vec[0]);
        int count =0;
        for(int i = 1; i < a; i++)
        {
            if(min(vec[i], g-vec[i]) >= vec[i-1])
            {
                vec[i] = min(vec[i], g-vec[i]);
            }
            else if(max(vec[i], g-vec[i]) >= vec[i-1])
            {
                vec[i] = max(vec[i], g-vec[i]);
            }
            else
            {
                cout << "NO\n";
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << "YES\n";
        }
    }
}