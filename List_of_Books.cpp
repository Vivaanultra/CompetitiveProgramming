#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
    {
        int roomba;
        cin >> roomba;
        vec[i] = roomba;
    }
    int count;
    cin >> count;
    vector<int> vec2(count);
    for (int j=0; j<count; j++)
    {
        int a;
        cin >> a;
        vec2[j] = vec[a-1];
        for(int k = a; k < n; k++)
        {
            vec[k-1] = vec[k];
        }
    }
    for(int l=0; l<count; l++)
    {
        cout << vec2[l] << endl;
    }
}