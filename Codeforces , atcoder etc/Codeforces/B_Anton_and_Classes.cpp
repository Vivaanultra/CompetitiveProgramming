#include <bits/stdc++.h>
using namespace std;


int main()
{
    int class1;
    cin >> class1;
    vector<int> c1b(class1);
    vector<int> c1e(class1);
    for (int i = 0; i < class1; i++)
    {
        cin >> c1b[i];
        cin >> c1e[i];
    }
    int class2;
    cin >> class2;
    vector<int> c2b(class2);
    vector<int> c2e(class2);
    for (int i = 0; i < class2; i++)
    {
        cin >> c2b[i];
        cin >> c2e[i];
    }
    int answer = max(*max_element(c2b.begin(), c2b.end())-*min_element(c1e.begin(), c1e.end()),*max_element(c1b.begin(), c1b.end())-*min_element(c2e.begin(), c2e.end()));
    cout << max(answer, 0) << "\n";
}