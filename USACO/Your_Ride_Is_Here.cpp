/*
ID: vivaans1
PROG: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    
    string n;
    cin >> n;
    string s;
        cin >> s;
        
        int prod1 = 1, prod2 = 1;
        
        for(char c : n) {
            prod1 *= (c - 'A' + 1);
            prod1 %= 47;
        }
    
        for(char c : s) {
            prod2 *= (c - 'A' + 1);
            prod2 %= 47;
        }
        
        if(prod1 == prod2)
            cout << "GO" << endl;
        else
            cout << "STAY" << endl;
    
}