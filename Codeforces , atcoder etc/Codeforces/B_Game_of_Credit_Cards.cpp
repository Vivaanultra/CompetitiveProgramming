#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length;
    std::cin >> length;
    string s1, s2;
    std::cin >> s1 >> s2;
    int count = 0;
    sort(s2.begin(), s2.end());
    int flickgiven = 0;
    string s3 = s2;
    for (int i = 0; i < length; i++)
    {
        auto it = lower_bound(s3.begin(), s3.end(), s1[i]);
        if (it != s3.end())
        {
            s3.erase(it);
        }
        else
        {
            s3.erase(s3.begin());
            count++;
        }
    }
    std::cout << count << std::endl;
    for (int i = 0; i < length; i++)
    {
        auto it = upper_bound(s2.begin(), s2.end(), s1[i]);
        if (it != s2.end())
        {
            flickgiven++;
            s2.erase(it);
        }
    }
    std::cout << flickgiven << std::endl;
}