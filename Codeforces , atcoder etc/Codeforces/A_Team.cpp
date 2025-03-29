#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int e = 0;
    for (int i=0; i<a; i++)
    {
        int b, c, d;
        
        cin >> b >> c >> d;
        if (b+c+d >= 2)
        {
            e++;
        }
    }
    cout << e;
}