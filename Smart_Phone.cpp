#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> customerbud(n);
    vector<long long int> revenue(n);
    for(long long int i=0; i<n; i++)
    {
        cin >> customerbud[i];
    }
    sort(customerbud.begin(), customerbud.end());
    for(long long int j=0; j<n; j++)
    {
        long long int a = customerbud[j] * (n-j);
        revenue[j] = a;
    }
    sort(revenue.begin(), revenue.end());
    cout << revenue[n-1];

}