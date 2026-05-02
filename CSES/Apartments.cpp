#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int app , apa , diff;
    cin >> app >> apa >> diff;
    vector<long long> a(app);
    vector<long long> b(apa);
    for(int i = 0 ; i < app ; i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i < apa ; i++)
    {
        cin >> b[i];
    }
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    long long ans = 0;
    int apln = 0;
    int apan = 0;
    int cons = app + apa;
    while(cons--)
    {
        if(b[apan] >= a[apln] - diff && b[apan] <= a[apln] + diff)
        {
            ans++;
            apln++;
            apan++;
        }
        else if(a[apln] < b[apan])
        {
            apln++;
        }
        else
        {
            apan++;
        }
        if(apln == app || apan == apa)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}