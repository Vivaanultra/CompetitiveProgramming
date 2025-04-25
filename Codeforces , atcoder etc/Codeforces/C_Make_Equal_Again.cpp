#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int arrsize;
        cin >> arrsize;
        vector<int> arr;
        for (int j = 0; j < arrsize; j++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        int dupebegincount = 1;
        int dupeendcount = 1;
        int dupebegin = arr[0];
        int dupeend = arr[arrsize - 1];
        for (int j = 1; j < arrsize; j++)
        {
            if (arr[j] == dupebegin)
            {
                dupebegincount++;
            }
            else
            {
                break;
            }
        }
        for (int j = arrsize - 2; j >= 0; j--)
        {
            if (arr[j] == dupeend)
            {
                dupeendcount++;
            }
            else
            {
                break;
            }
        }
        if( dupebegin == dupeend)
        {
            cout << max(0, arrsize - dupebegincount - dupeendcount) << endl;
        }
        else
        {
            cout << min(arrsize - dupebegincount , arrsize - dupeendcount )<< endl;
        }
    }
}