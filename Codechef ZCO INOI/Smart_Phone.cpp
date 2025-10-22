#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int len;
    cin >> len;
    vector<long long int> a(len);
    vector<long long int> b(len);
    for(long long int i = 0; i < len; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(long long int i = 0; i < len; i++)
    {
        b.push_back(a[i]*(len - (lower_bound(a.begin(), a.end(), a[i]) - a.begin())));
    }
    cout << *max_element(b.begin(), b.end()) << "\n";
    
}