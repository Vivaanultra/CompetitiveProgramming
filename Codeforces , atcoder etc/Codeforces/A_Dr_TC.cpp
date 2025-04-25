#include <bits/stdc++.h>
using namespace std;


int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int num;
        cin >> num;
        string str;
        cin >> str;
        int count = 0;
                for(int j = 0; j < num; j++) {
                    string temp = str;
                    temp[j] = (temp[j] == '1') ? '0' : '1';
                    for(int k = 0; k < num; k++) {
                        if(temp[k] == '1') count++;
                    }
                }
                cout << count << endl;
        
    }
}