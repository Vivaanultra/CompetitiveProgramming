#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, s, r;
    cin >> n >> s >> r;

    // The value of the stolen die is s - r. This is also the maximum value.
    int max_val = s - r;
    cout << max_val << " ";

    // We need to find n-1 other dice values that sum to r.
    int remaining_dice = n - 1;
    
    // Distribute the sum r as evenly as possible among the remaining dice.
    int base_val = r / remaining_dice;
    int extra = r % remaining_dice;

    for (int i = 0; i < remaining_dice; ++i) {
        int current_val = base_val;
        // The first 'extra' dice get one more to account for the remainder.
        if (extra > 0) {
            current_val++;
            extra--;
        }
        cout << current_val << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}