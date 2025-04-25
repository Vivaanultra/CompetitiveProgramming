#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n;
        cin >> n;
        vector<int> v(2*n);
        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >>x;
                v[i+j] = x;
            }
        }
        vector<int> v2(2*n);
        for(int i = 1; i <= 2*n; i++) {
            v2[i-1] = i;
        }
        int missingnumber;
        for(int i = 0; i < 2*n; i++) {
            bool found = false;
            for(int j = 0; j < 2*n-1; j++) {
                if(v2[i] == v[j]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                missingnumber = v2[i];
                break;
            }
        }
        cout << missingnumber << " ";
        for(int i = 0; i < 2*n - 1; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}