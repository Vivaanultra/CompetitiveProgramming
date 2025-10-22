#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    int k;
    cin >> n >> k;
    vector<long long> x(k);
    for (int i = 0; i < k; ++i) {
        cin >> x[i];
    }

    // Step 1: Prioritize mice by sorting them closest to the hole first.
    sort(x.rbegin(), x.rend());

    long long cat_pos = 0;
    int saved_mice = 0;

    // Step 3: Evacuate one by one.
    for (int i = 0; i < k; ++i) {
        // Check if the cat has already passed this mouse's position.
        if (cat_pos >= x[i]) {
            // If so, we can't save this or any subsequent mice.
            break;
        }

        // We can save this mouse.
        saved_mice++;
        
        // Pay the cost: the cat moves forward by the distance the mouse had to travel.
        long long cost = n - x[i];
        cat_pos += cost;
    }

    cout << saved_mice << endl;
}

int main() {
    // It is currently Monday, 7:00 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}