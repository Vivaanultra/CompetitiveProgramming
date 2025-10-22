#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    // --- Determine dominant character and swap if needed ---
    char dominant_char = '0';
    char other_char = '1';
    bool swapped = false;
    if (m > n) {
        swap(n, m);
        swapped = true;
    }

    // --- Check impossible conditions ---
    // The max possible balance is n (a string of all dominant chars).
    // The balance of the whole string is n-m, which must be <= k.
    if (k > n || k < n - m) {
        cout << -1 << "\n";
        return;
    }
    
    // --- Construct the string ---
    string result = "";
    
    // 1. Create a prefix of k dominant characters.
    for (int i = 0; i < k; ++i) {
        result += dominant_char;
    }
    n -= k; // Use up k dominant characters.

    // 2. Alternate the remaining chars to keep the balance low.
    while (n > 0 && m > 0) {
        result += other_char;
        result += dominant_char;
        m--;
        n--;
    }
    
    // 3. Append any leftovers.
    while (n > 0) {
        result += dominant_char;
        n--;
    }
    while (m > 0) {
        result += other_char;
        m--;
    }
    
    // 4. If we swapped initially, swap the characters back.
    if (swapped) {
        for (char &c : result) {
            c = (c == '0' ? '1' : '0');
        }
    }

    cout << result << "\n";
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