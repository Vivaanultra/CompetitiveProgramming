#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // t = number of test cases
    int t;
    cin >> t;
    
    while(t--){
        // Read the sizes of the two arrays and the value k
        int n, m, k;
        cin >> n >> m >> k;
        
        // Read array a (size n)
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        // Read array b (size m)
        vector<int> b(m);
        for (int i = 0; i < m; i++){
            cin >> b[i];
        }
        
        // We need to select exactly k/2 numbers from each array.
        // Let r be k/2.
        int r = k / 2;
        
        // We only care about numbers in the range [1, k].
        // Create two frequency arrays (size k+1, so index 1..k are used)
        vector<int> freqA(k + 1, 0);
        vector<int> freqB(k + 1, 0);
        
        // Count occurrences for numbers 1 to k in array a
        for (int i = 0; i < n; i++){
            int x = a[i];
            if (x >= 1 && x <= k)
                freqA[x]++;
        }
        
        // Count occurrences for numbers 1 to k in array b
        for (int i = 0; i < m; i++){
            int x = b[i];
            if (x >= 1 && x <= k)
                freqB[x]++;
        }
        
        // We need to check two things:
        // 1. Every number from 1 to k must appear in at least one array.
        // 2. We cannot be forced to choose more than r numbers from one array.
        //    (A number is "forced" if it appears in only one array.)
        
        bool possible = true;  // Will become false if conditions are not met
        
        int forcedA = 0;  // Count of numbers that appear only in array a.
        int forcedB = 0;  // Count of numbers that appear only in array b.
        
        // Check for each number x from 1 to k:
        for (int x = 1; x <= k; x++){
            // If x does not appear in either array, it's impossible to cover [1,k].
            if (freqA[x] + freqB[x] == 0) {
                possible = false;
                break;
            }
            // If x appears only in array a, it must come from a.
            if (freqA[x] > 0 && freqB[x] == 0) {
                forcedA++;
            }
            // If x appears only in array b, it must come from b.
            if (freqB[x] > 0 && freqA[x] == 0) {
                forcedB++;
            }
        }
        
        // Check if the forced numbers exceed the quota (r) for either array.
        // Since we must choose exactly r numbers from each array,
        // if forcedA > r or forcedB > r, then it's not possible.
        if (forcedA > r || forcedB > r)
            possible = false;
        
        // Output the answer
        if (possible)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    
    return 0;
}
