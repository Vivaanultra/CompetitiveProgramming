#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    vector<int> results;
    for(int i = 0; i < 2000; i++)
    {
        if(results.size() == 1000)
        {
            break;
        }
        if (i % 3 == 0 || i % 10 == 3)
        {
            continue;
        }
        results.push_back(i);
    }
    while(t--)
    {
        int n;
        cin >> n;
        cout << results[n-1] << endl;
    }
}