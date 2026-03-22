#include <bits/stdc++.h>
using namespace std;


bool suneetWins(int s1, int s2, int sl1, int sl2) {
    int suneet_rounds = 0;
    int slavic_rounds = 0;

    
    if (s1 > sl1) suneet_rounds++;
    else if (sl1 > s1) slavic_rounds++;

    
    if (s2 > sl2) suneet_rounds++;
    else if (sl2 > s2) slavic_rounds++;

    
    return suneet_rounds > slavic_rounds;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int ways = 0;

        
        
        if (suneetWins(a1, a2, b1, b2)) {
            ways += 2;
        }

        
        
        if (suneetWins(a1, a2, b2, b1)) {
            ways += 2;
        }

        cout << ways << "\n";
    }
    return 0;
}