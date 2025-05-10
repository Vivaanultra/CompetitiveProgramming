#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int length;
        int ops;
        string s;
        cin >> length >> ops >> s;
        if(length > 1)
        {
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(s < rev) {
                cout << "YES" << "\n";
                continue;
            }
            if(ops)
            { 
                char maxl = *max_element(s.begin (), s.end() - 1);
                char minl = *min_element(s.begin()+1, s.end());
                if(maxl > s[length - 1] or minl < s[0])
                {
                    cout << "YES" << "\n";
                }
                else
                {
                    cout << "NO" << "\n";

                }
            }
            else
            {
                cout << "NO" << "\n";
            }        
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}