#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testcases;
    cin >> testcases;
    bool somewherefound = false;
    for (int i = 0; i < testcases; i++)
    {
        int menuitems;
        cin >> menuitems;
        string name;
        cin.ignore(); // Add this to handle the newline after menuitems
        getline(cin, name); // Add this to get the restaurant name
        bool ispeasoup = false;
        bool cake = false;
        for (int j = 0; j < menuitems; j++)
        {
            string item;
            getline(cin, item);
            if (item == "pea soup")
            {
                ispeasoup = true;
            }
            if (item == "pancakes")
            {
                cake = true;
            }
        }
        if (ispeasoup && cake)
        {
            somewherefound = true;
            cout << name << endl;
            return 0;
        }
    }
    if (!somewherefound)
    {
        cout << "Anywhere is fine I guess" << endl;
    }
}