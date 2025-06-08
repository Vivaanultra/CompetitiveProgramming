#include <bits/stdc++.h>
using namespace std;


int main()
{
    int no_of_holes;
    cin >> no_of_holes;
    int holecount[no_of_holes + 1];
    holecount[0] = 0;
    int sum = 0;
    for (int i = 1; i <= no_of_holes; i++)
    {
        int x;
        cin >> x;
        sum += x;
        holecount[i] = sum;
    }
    int no_of_worms;
    cin >> no_of_worms;
    while(no_of_worms--)
    {
        int worm;
        cin >> worm;
        int index = lower_bound(holecount, holecount + no_of_holes + 1, worm) - holecount;
        cout << index << endl;
    }
}