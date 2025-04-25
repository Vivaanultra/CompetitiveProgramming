#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        string s;
        cin >> n >> s;

        // 1) count how many '<' so we know our starting stick
        int countL = 0;
        for(char c: s) if(c == '<') ++countL;

        vector<int> a(n);
        // 2) place the first stick
        a[0] = countL + 1;
        int low = a[0], high = a[0];

        // 3) build the rest
        for(int i = 0; i < n-1; i++){
            if(s[i] == '<'){
                // need a new record low
                a[i+1] = low - 1;
                low = a[i+1];
            } else {
                // need a new record high
                a[i+1] = high + 1;
                high = a[i+1];
            }
        }

        // output
        for(int x: a) 
            cout << x << ' ';
        cout << "\n";
    }
    return 0;
}
