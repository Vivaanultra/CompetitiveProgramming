#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    for (int i=0; i<a; i++)
    {
        long long int b;
        cin >> b;
        if (b%3 == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}