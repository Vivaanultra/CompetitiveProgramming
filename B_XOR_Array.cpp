#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        int prev_p = 0; 
        
        for (int i = 1; i <= n; i++)
        {
            int curr_p;
            
            
            
            
            if (i == r) {
                curr_p = l - 1; 
            }
            else {
                
                curr_p = i;
            }

            
            cout << (curr_p ^ prev_p) << " ";
            
            
            prev_p = curr_p;
        }
        cout << "\n";
    }
    return 0;
}