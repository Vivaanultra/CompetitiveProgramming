#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int ln;
        cin >> ln;
        string s;
        cin >> s;
        int onecnt = 0;
        int zercnt = 0;
        for(int i = 0; i < ln; i++)
        {
            if(s[i] == '1')
            {
                onecnt++;
            }
            else{
                zercnt++;
            }
        }
        int ans = onecnt*(onecnt - 1) + zercnt*(onecnt + 1);
        cout << ans << "\n";
    }
    return 0;
}