#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> bigrams(n - 2);
    for (int i = 0; i < n - 2; ++i) {
        cin >> bigrams[i];
    }

    // Start the word with the first bigram
    string result = bigrams[0];
    bool gap_found = false;

    // Chain the rest of the bigrams
    for (int i = 1; i < n - 2; ++i) {
        // Check if the chain is broken
        if (result.back() != bigrams[i][0]) {
            result += bigrams[i];
            gap_found = true;
        } else {
            result += bigrams[i][1];
        }
    }

    // Handle the edge case where the missing bigram was at the end
    if (!gap_found) {
        result += 'a';
    }

    cout << result << endl;
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