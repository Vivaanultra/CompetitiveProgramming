#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int permlen;
        cin >> permlen;
        vector<int> perm(permlen);
        for (int i = 0; i < permlen; i++)
        {
            cin >> perm[i];
        }
        auto s = max_element(perm.begin(),perm.end());
        int max = *s;
        auto left = s;
        auto right = s;
        bool flag = false;
        for (int i = 0; i < permlen - 1; i++)
        {
            if (left != perm.begin() && *(left - 1) == max - 1)
            {
                left--;
                max--;
                continue;
            }
            else if(right != perm.end() - 1 && *(right + 1) == max - 1)
            {
                right++;
                max--;
                continue;
            }
            else
            {
                flag = true;
                break;  
            }
            
        }
        if(flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}