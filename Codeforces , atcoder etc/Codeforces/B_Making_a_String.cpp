#include<bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    sort(a.begin(), a.end(), greater<long long>());

    long long total_length = 0;



    long long prev_count = 2000000007LL; 

    for (int i = 0; i < n; ++i) {
    
    
    
    
        long long current_count = max(0LL, min(a[i], prev_count - 1));


        total_length += current_count;

        prev_count = current_count;

        if (prev_count == 0) {
            break;
        }
    }

    cout << total_length << "\n";

    return 0;
}