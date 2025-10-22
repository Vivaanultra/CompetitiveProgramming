#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    // 1. Find the largest number of initial positive elements, i,
    // such that the number of positive subarrays from them does not exceed k.
    int i = 0;
    while (i < n && (long long)(i + 1) * (i + 2) / 2 <= k) {
        i++;
    }

    // k_base is the number of positive subarrays from the first 'i' elements.
    long long k_base = (long long)i * (i + 1) / 2;
    // rem is the remaining number of positive subarrays we still need to create.
    int rem = k - k_base;

    vector<int> a(n);

    // 2. Set the first 'i' elements to a small positive value.
    for (int j = 0; j < i; ++j) {
        a[j] = 2;
    }

    // 3. Craft the (i+1)-th element to generate the 'rem' subarrays.
    if (i < n) {
        if (rem == 0) {
            // If no more positive subarrays are needed, make this element
            // and all subsequent ones large and negative.
            a[i] = -1000;
        } else {
            // This element X must be chosen such that exactly 'rem' new
            // subarrays that end at this position have a positive sum.
            // The value -2*(i - rem + 1) + 1 satisfies this.
            int x = -2 * (i - rem + 1) + 1;
            a[i] = x;
        }
    }
    
    // 4. Fill the rest of the array with a large negative value.
    for (int j = i + 1; j < n; ++j) {
        a[j] = -1000;
    }

    // Print the constructed array
    for (int j = 0; j < n; ++j) {
        cout << a[j] << (j == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}