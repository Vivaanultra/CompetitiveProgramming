#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int length;
        cin >> length;
        vector<int> numbers(length);
        for (int i = 0; i < length; i++)
        {
            cin >> numbers[i];
        }
        unordered_map<int, int> freq;
                int duplicates = 0;
                for (int num : numbers)
                {
                    freq[num]++;
                }
                for (auto &entry : freq)
                {
                    if (entry.second > 1)
                        duplicates += entry.second - 1;
                }
                if(duplicates%2 == 0)
                {
                    cout << length - duplicates << "\n";
                }
                else
                {
                    cout << length - duplicates - 1 << "\n";
                }
        
    }
    return 0;
}