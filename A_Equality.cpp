#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (cin >> n >> k) {
        string s;
        cin >> s;

        
        
        vector<int> counts(k, 0);

        for (char c : s) {
            
            counts[c - 'A']++;
        }

        
        
        int min_freq = *min_element(counts.begin(), counts.end());

        
        cout << min_freq * k << endl;
    }

    return 0;
}