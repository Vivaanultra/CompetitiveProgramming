#include <bits/stdc++.h>

// Using std namespace for convenience in competitive programming
using namespace std;

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    long long current_length = 0;
    int words_on_strip = 0;

    // Greedily add words until the strip is full
    for (int i = 0; i < n; ++i) {
        if (current_length + words[i].length() <= m) {
            current_length += words[i].length();
            words_on_strip++;
        } else {
            // Cannot add the current word, so we stop
            break;
        }
    }

    cout << words_on_strip << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}