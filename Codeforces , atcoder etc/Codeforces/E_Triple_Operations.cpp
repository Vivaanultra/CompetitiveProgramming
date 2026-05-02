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
        int l, r;
        cin >> l >> r;

        long long total_ops = 0;
        int current_cost = 1;
        
        
        
        
        int cost_l = 0;
        int temp_l = l;
        while(temp_l > 0) {
            temp_l /= 3;
            cost_l++;
        }

        
        
        
        
        long long curr = 1;
        while (curr <= r)
        {
            long long next_val = curr * 3;
            
            
            long long lower_bound = max((long long)l, curr);
            long long upper_bound = min((long long)r, next_val - 1);

            if (lower_bound <= upper_bound)
            {
                long long count = upper_bound - lower_bound + 1;
                total_ops += count * current_cost;
            }

            curr = next_val;
            current_cost++;
        }

        
        total_ops += cost_l;

        cout << total_ops << "\n";
    }
    return 0;
}