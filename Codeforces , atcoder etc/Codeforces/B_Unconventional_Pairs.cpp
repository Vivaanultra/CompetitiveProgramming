#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        vector<int> a(len);
        for(int i = 0; i < len; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int max_diff = 0;
        for(int i = 1; i < len; i+=2)
        {
            max_diff = max(max_diff, a[i] - a[i-1]);
        }
        cout << max_diff << "\n";
    }
    return 0;
}