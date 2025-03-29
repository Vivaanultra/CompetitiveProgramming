#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int y;
    cin >> y;
    int z[x];
    for (int i=0; i<x; i++)
    {
        cin >> z[i];
    }
    int a = z[y-1];
    int b = 0;
    int count = 0;
    for (int b ; b<x; b++)
    {
        while(z[b] >= a && z[b] > 0)
        {
            count++;
            break;
        }
    }
    cout << count;
}
