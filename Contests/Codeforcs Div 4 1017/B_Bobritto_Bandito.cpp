#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int total_days;
        int required_days;
        int rangestart;
        int rangeend;
        cin >> total_days >> required_days >> rangestart >> rangeend;
        int targetrangebegin = 0;
        int targetrangeend = 0;
        for(int i = 0; i < required_days; i++)
        {
            if(targetrangebegin > rangestart)
            {
                targetrangebegin--;
            }
            else
            {
                targetrangeend++;
            }
        
        }
        cout << targetrangebegin << " " << targetrangeend << "\n";
    }
}
