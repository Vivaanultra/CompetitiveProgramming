#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if(a=="abc" || a=="acb" || a=="bac" || a=="cba")
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}