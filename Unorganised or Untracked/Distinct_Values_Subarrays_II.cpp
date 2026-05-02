#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long len, k;
    cin >> len >> k;
    vector<long long> a(len);
    for(long long i = 0; i < len; i++)
    {
        cin >> a[i];
    }
    long long left = 0;
    long long ans = 0;
    map<long long, int> freq;
    for(long long right = 0; right < len; right++)
    {       
        freq[a[right]]++;        
        while(freq.size() > k)
        {
            freq[a[left]]--;           
            if(freq[a[left]] == 0)
            {
                freq.erase(a[left]);
            }
            left++;
        }       
        ans += (right - left + 1);
    }
    cout << ans << endl;
    return 0;
}