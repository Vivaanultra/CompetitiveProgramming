#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        vector<int> v(len);
        for (int i = 0; i < len; i++)
        {
            cin >> v[i];
        }
        bool flag = false;
        for(int i=2; i <= *max_element(v.begin(), v.end()); i++)
        {
            int yec = 0;
            int nac = 0;
            vector<int> yea(len);
            for(int j=0; j < len; j++)
            {
                if(v[j] % i == 0)
                {
                    yea[j] = 1;
                    yec++;
                }
                else
                {
                    yea[j] = 2;
                    nac++;
                }
            }
            if(yec != 0 and nac != 0)
            {
                cout << "Yes" << endl;
                for(auto x : yea)
                {
                    cout << x << " ";
                }
                cout << endl;
                flag = true;
                break;
            
            }
        }
        if(!flag)
        {
            cout << "No" << endl;
        }
    }
    return 0;
}