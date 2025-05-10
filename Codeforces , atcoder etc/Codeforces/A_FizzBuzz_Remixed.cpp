#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        
        // Calculate complete cycles
        long long complete_cycles = n / 15;
        long long count = complete_cycles * 3; // 3 numbers per cycle: 0, 1, 2
        
        // Check remaining numbers
        long long remainder = n % 15;
        for(int i = 0; i <= remainder; i++)
        {
            if(i%3 == i%5)
            {
                count++;
            }
        }
        
        cout << count << "\n";
    }
    return 0;
}
