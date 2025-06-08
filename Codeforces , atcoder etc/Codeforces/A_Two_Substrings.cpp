#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool found = false;
    
    // Check AB...BA
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B') {
            for (int j = i + 2; j < s.size() - 1; j++) {
                if (s[j] == 'B' && s[j + 1] == 'A') {
                    found = true;
                    break;
                }
            }
            break;
        }
    }
    
    // Check BA...AB
    if (!found) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == 'B' && s[i + 1] == 'A') {
                for (int j = i + 2; j < s.size() - 1; j++) {
                    if (s[j] == 'A' && s[j + 1] == 'B') {
                        found = true;
                        break;
                    }
                }
                break;
            }
        }
    }
    
    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}