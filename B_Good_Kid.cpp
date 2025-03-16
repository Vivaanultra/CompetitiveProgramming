#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<int> vec(x);
        int y = 1;
        for (int j = 0; j < x; j++)
        {
            cin >> vec[j];
        }
    sort(vec.begin(), vec.end());
    vec[0] = vec[0] + 1;
    for (int k = 0; k < x; k++)
    {
        y *= vec[k];
    }
    cout << y << endl;
}
}