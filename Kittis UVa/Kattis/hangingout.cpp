#include <bits/stdc++.h>
using namespace std;
int main()
{
    int L;
    int X;
    cin >> L >> X;
    int totaldenied = 0;
    int current = 0;
    for (int i = 0; i < X; i++)
    {
        string s;
        cin >> s;
        int num;
        cin >> num;
        if (s == "enter")
        {
            if (current + num > L)
            {
                totaldenied++;
            }
            else
            {
                current += num;
            }
        }
        else
        {
            current -= num;
        }
    }
    cout << totaldenied << endl;
}