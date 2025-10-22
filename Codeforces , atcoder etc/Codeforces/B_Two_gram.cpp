#include <bits/stdc++.h>
using namespace std;
int main()
{
    int letters;
    cin >> letters;
    string s;
    cin >> s;
    unordered_map<string,int> mp;
    for(int i=0;i<letters - 1;i++)
    {
        // Create a substring of length 2 starting at index i
        mp[s.substr(i, 2)]++;
    }

    string max_gram;
    int max_count = 0;
    for(auto const& [gram, count] : mp)
    {
        if(count > max_count)
        {
            max_count = count;
            max_gram = gram;
        }
    }
    cout << max_gram << endl;
    return 0;
}