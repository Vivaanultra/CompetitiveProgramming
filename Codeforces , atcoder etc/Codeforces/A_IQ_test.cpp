#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int even = 0, odd = 0;
    int lastEven = 0, lastOdd = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] % 2 == 0) {
            even++;
            lastEven = i + 1;
        } else {
            odd++;
            lastOdd = i + 1;
        }
    }
    
    if(even == 1) {
        cout << lastEven << "\n";
    } else {
        cout << lastOdd << "\n";
    }
    return 0;
}