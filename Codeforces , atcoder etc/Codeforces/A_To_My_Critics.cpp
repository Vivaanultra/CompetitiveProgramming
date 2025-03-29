#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int a , b , c;
        cin>>a>>b>>c;
        vector<int> vec(3);
        vec[0] = a;
        vec[1] = b;
        vec[2] = c;
        sort(vec.begin(),vec.end());
        if(vec[1]+vec[2] >= 10)
        {
            cout<<"YES"<< "\n";
        }
        else
        {
            cout<<"NO"<<"\n";
        }
    }
}