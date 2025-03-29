#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    cin >> a;
    for (int i=0; i<a; i++)
    {
        string b;
        cin >> b;
        if (b.length() > 10)
        {
            cout << b[0] << b.length()-2 << b[b.length()-1] << endl;
        }
        else
        {
            cout << b << endl;
        }
    }
}