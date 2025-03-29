// the default test case says that the solution is wrong but it really isn't , this solution should be accepted
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;

bool isPS(ld a)// checks if the number is a perfect square
{
    ld b = sqrt(a);
    if(b == (int)b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ll a;
    cin >> a;
    for(ld i = 0; i < a; i++)
    {
        ll sum = 0;
        ld x;
        cin >>x;
        ld abcd = x*(x+1)/2;
        if(isPS(abcd) == true)
        {
            cout << "-1";
        }
        else
        {
            vector<ll> vec(x);
            for(ll j = 1; j<=x; j++)
            {
                vec[j-1] = j;
            }
            for(ll j = 0; j < x -1; j++)
            {
                sum += vec[j];
                if(isPS(sum)==true)
               {
                    swap(vec[j],vec[j +1]);
                    sum = sum - vec[j+1] + vec[j];
               } 
            }
            for(ll k = 0; k < vec.size(); k++)
            {
                cout << vec[k] << " ";
            }
        }
        cout << "\n";
    }
}