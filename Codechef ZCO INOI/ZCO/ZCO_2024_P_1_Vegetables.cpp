#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    // Read input values for Demand and Water for each vegetable.
    vector<ll> Demand(n), Water(n);
    for (int i = 0; i < n; i++){
        cin >> Demand[i];
    }
    for (int i = 0; i < n; i++){
        cin >> Water[i];
    }
    
    // Construct pairs for each vegetable.
    // a represents the maximum of Demand and Water,
    // b represents the minimum (or a itself if they are equal).
    // The initial "value" for each vegetable is a * b.
    vector<pair<ll,ll>> pairs(n);
    for (int i = 0; i < n; i++){
        ll a = max(Demand[i], Water[i]);
        ll b = (Demand[i] == Water[i]) ? Demand[i] : min(Demand[i], Water[i]);
        pairs[i] = {a, b};
    }
    
    // Calculate the total initial sum (i.e., before any operations).
    ll totalInitial = 0;
    for (int i = 0; i < n; i++){
        totalInitial += pairs[i].first * pairs[i].second;
    }
    // sorts the pairs in descending order based on the first element (a). if a is equal, it sorts based on the second element (b).
    sort(pairs.rbegin(), pairs.rend());
    
    // Precompute prefix sums:
    // prefixB[i] holds the cumulative sum of b's from pairs[0] to pairs[i]. 
    // This represents the maximum number of operations that can be applied on these pairs.
    // prefixReduction[i] holds the cumulative sum of (a * b) for pairs[0] to pairs[i],
    // which is the total reduction if all available operations are applied to these pairs.
    int sz = pairs.size();
    vector<ll> prefixB(sz), prefixReduction(sz);
    prefixB[0] = pairs[0].second;
    prefixReduction[0] = pairs[0].first * pairs[0].second;
    for (int i = 1; i < sz; i++){
        prefixB[i] = prefixB[i-1] + pairs[i].second;
        prefixReduction[i] = prefixReduction[i-1] + pairs[i].first * pairs[i].second;
    }
    
    // Process each query:
    // For each query we are given a number of operations (x).
    // We want to distribute these operations to achieve maximum reduction.
    // We find how many vegetables can have all of their b operations applied 
    // using binary search on the prefixB array.
    while(q--){
        ll x;
        cin >> x;
        
        // If the available operations exceed or equal the sum of all b's,
        // then every vegetable is fully processed, and the final sum is 0.
        if(x >= prefixB[sz-1]){
            cout << 0 << "\n";
            continue;
        }
        
        // Binary search for the highest index where the cumulative operations (prefixB)
        // do not exceed the available operations x.
        int lo = 0, hi = sz - 1, pos = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(prefixB[mid] <= x){
                pos = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        // The total reduction from vegetables that are fully processed.
        ll reduction = (pos >= 0 ? prefixReduction[pos] : 0);
        ll usedOps = (pos >= 0 ? prefixB[pos] : 0);
        
        // For the next vegetable, only a partial number of operations (remain) can be applied.
        int next = pos + 1;
        if(next < sz){
            ll remain = x - usedOps;
            reduction += pairs[next].first * remain;
        }
        
        // The final answer is the initial sum minus the total reduction achieved.
        ll result = totalInitial - reduction;
        cout << result << "\n";
    }
    return 0;
}