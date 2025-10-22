#include <bits/stdc++.h>
using namespace std;
#define inf 1e9 + 7

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) 
    {
        int a =inf , b = inf , c = inf;
        int length;
        cin >> length;
        for (int i = 0; i < length; i++)
        {
            int read;
            string skill;
            cin >> read >> skill;
            if (skill == "11")
            {
                c = min(c , read);
            }
            else if (skill == "10")
            {
                a = min(a , read);
            }
            else if (skill == "01")
            {
                b = min(b , read);
            }
        }
        int answer = min(a + b , c);
        if (answer == inf)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << answer << "\n";
        }
    }
    

}