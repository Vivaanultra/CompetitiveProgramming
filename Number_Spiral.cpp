#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while(t--)
    {
        long long x , y;
        cin >> x >> y;
        long long sig = max(x , y);
        long long mini = min(x , y);
        if(sig == mini && mini == 1)
        {
            cout << 1 << endl;
            continue;
        }
        long long sum = 0;
        if(y > x)
        {
            if(sig%2 == 1)
            {
                sum += sig*sig;
                sum -= mini -1;
                cout << sum << endl;
            }
            else
            {
                sum += (sig-1)*(sig-1) + 1;
                sum += mini -1;
                cout << sum << endl;
            }
        }
        else
        {
            if(sig%2 == 0)
            {
                sum += sig*sig;
                sum -= mini -1;
                cout << sum << endl;
            }
            else
            {
                sum += (sig-1)*(sig-1) + 1;
                sum += mini -1;
                cout << sum << endl;
            }
        }
    }
}