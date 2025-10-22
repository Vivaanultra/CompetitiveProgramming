#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    
    // Sort the numbers
    sort(nums.begin(), nums.end());
    
    // The medium number is the one in the middle
    cout << nums[1] << endl;
}

int main() {
    // It is currently Friday, 4:53 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}