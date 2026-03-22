#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len;
    cin >> len;
    set<long long> s;
    for (int i = 0; i < len; i++)
    {
        long long x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}