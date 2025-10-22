#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long k; // K can be large, but the values fit in int.
                 // Using long long for K is safer practice.
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    long long ans = 0; // The answer can exceed the int limit.
    
    // For each element a[i]...
    for(int i = 0; i < n; i++)
    {
        // ...we want to find how many elements a[j] with j > i
        // satisfy a[j] >= a[i] + k.
        
        // Find the first element in the rest of the array (from a[i+1] onwards)
        // that is >= a[i] + k.
        auto it = lower_bound(a.begin() + i + 1, a.end(), a[i] + k);
        
        // The number of such elements is the distance from that iterator to the end.
        ans += distance(it, a.end());
    }
    
    cout << ans << "\n";
}