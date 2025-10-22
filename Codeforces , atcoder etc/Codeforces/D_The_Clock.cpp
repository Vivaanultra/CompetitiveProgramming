#include <bits/stdc++.h>
using namespace std;

string addxmins(string time, int mins)
{
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');
    minute += mins;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
    string ans = "";
    if (hour < 10)
    {
        ans += '0';
    }
    ans += to_string(hour);
    ans += ':';
    if (minute < 10)
    {
        ans += '0';
    }
    ans += to_string(minute);
    return ans;
}

bool isPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string time;
        cin >> time;
        string initial_time = time;
        int minutes;
        cin >> minutes;
        int valid = true;
        int palcount = 0;
        time = addxmins(time, minutes);
        while(valid)
        {
            if(isPalindrome(time))
            {
                palcount++;
            }
            
            if(time == initial_time)
            {
                valid = false;
            }
            time = addxmins(time, minutes);
        }
        cout << palcount << "\n";
    }
    return 0;
}