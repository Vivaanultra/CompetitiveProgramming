#include <bits/stdc++.h>
using namespace std;
int main()
{
    int alength,  blength;
    cin >> alength >> blength;
    vector<int> a(alength);
    vector<int> b(blength);
    for (int i = 0; i < alength; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < blength; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < blength; i++)
    {
        cout << upper_bound(a.begin(), a.end(), b[i]) - a.begin() << " ";
    }
}