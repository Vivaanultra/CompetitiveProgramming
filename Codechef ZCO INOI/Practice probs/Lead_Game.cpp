#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> plarr(n);
    int culma = 0;
    int culmb = 0;
    for(int i=0; i<n; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        culma += a;
        culmb += b;
        int c = culma - culmb;
        plarr[i] = c;
    }
    sort(plarr.begin(), plarr.end());
    if(plarr[n-1]+plarr[0] > 0)
    {
        cout << 1 << " " << plarr[n-1];
    }
    else
    {
        cout << 2 << " " << plarr[0]*-1;
    }
    
    
}