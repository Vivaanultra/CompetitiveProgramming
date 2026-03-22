#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    long long total_sum = n * (n + 1) / 2;

    
    if (total_sum % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        vector<int> set1, set2;
        int start_node = 1;

        
        
        if (n % 4 == 3) {
            set1.push_back(1);
            set1.push_back(2);
            set2.push_back(3);
            start_node = 4; 
        } 
        

        
        
        for (int i = start_node; i <= n; i += 4) {
            set1.push_back(i);        
            set1.push_back(i + 3);    
            set2.push_back(i + 1);    
            set2.push_back(i + 2);    
        }

        
        cout << set1.size() << "\n";
        for (int x : set1) {
            cout << x << " ";
        }
        cout << "\n";

        
        cout << set2.size() << "\n";
        for (int x : set2) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}