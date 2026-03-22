#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    
    // Sort the scores to easily find min (index 0), median (index 1), and max (index 2)
    sort(a, a + 3);
    
    // Check difference between max and min
    if (a[2] - a[0] >= 10) {
        cout << "check again" << endl;
    } else {
        cout << "final " << a[1] << endl;
    }
    
    return 0;
}