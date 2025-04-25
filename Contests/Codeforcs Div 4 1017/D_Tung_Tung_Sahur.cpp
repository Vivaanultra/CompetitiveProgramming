#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string p, s;
        cin >> p >> s;
        vector<pair<char, int>> pv; // Changed to store char and count
        vector<pair<char, int>> sv;
        int curr_count = 1;
        
        // Process pattern string
        for(int i = 0; i < p.size(); i++) {
            if(i + 1 < p.size() && p[i] == p[i + 1]) {
                curr_count++;
            } else {
                pv.push_back({p[i], curr_count});
                curr_count = 1;
            }
        }
        
        // Process sound string
        curr_count = 1;
        for(int i = 0; i < s.size(); i++) {
            if(i + 1 < s.size() && s[i] == s[i + 1]) {
                curr_count++;
            } else {
                sv.push_back({s[i], curr_count});
                curr_count = 1;
            }
        }
        
        bool isvalid = pv.size() == sv.size();
        if(isvalid) {
            for(int i = 0; i < pv.size(); i++) {
                // Each hit can sound once or twice
                // So pattern count * 2 >= sound count >= pattern count
                if(pv[i].first != sv[i].first || 
                   pv[i].second * 2 < sv[i].second || 
                   pv[i].second > sv[i].second) {
                    isvalid = false;
                    break;
                }
            }
        }
        
        cout << (isvalid ? "YES" : "NO") << "\n";
    }
}