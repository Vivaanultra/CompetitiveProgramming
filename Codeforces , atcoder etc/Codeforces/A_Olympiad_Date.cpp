#include <bits/stdc++.h>
using namespace std;   
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    cin >> testcases;
    vector<int> required = {0,1,0,3,2,0,2,5};  // 01032025
    vector<int> count(10, 0);
    for(int x : required) count[x]++;
    
    while(testcases--)
    {
        int length;
        cin >> length;
        vector<int> current(10, 0);
        int answer = -1;
        
        for(int i = 0; i < length; i++)
        {
            int x;
            cin >> x;
            current[x]++;
            
            bool possible = true;
            for(int d = 0; d < 10; d++) {
                if(current[d] < count[d]) {
                    possible = false;
                    break;
                }
            }
            
            if(possible && answer == -1) {
                answer = i + 1;
            }
        }
        
        cout << (answer == -1 ? 0 : answer) << "\n";
    }
}