#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.length();
    vector<int> count(26, 0);
    for (char c : s) count[c - 'A']++;

    int max_freq = 0;
    for (int c : count) max_freq = max(max_freq, c);

    if (max_freq > (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    string result = "";
    int last_char = -1;

    for (int i = 0; i < n; i++) {
        int best_char = -1;
        int remaining_len = n - i;

        
        int majority_char = -1;
        int current_max = -1;
        
        for (int c = 0; c < 26; c++) {
            if (count[c] > current_max) {
                current_max = count[c];
                majority_char = c;
            }
        }

        
        
        if (2 * current_max > remaining_len) {
            best_char = majority_char;
        } else {
            
            for (int c = 0; c < 26; c++) {
                if (count[c] > 0 && c != last_char) {
                    best_char = c;
                    break;
                }
            }
        }

        result += (char)('A' + best_char);
        count[best_char]--;
        last_char = best_char;
    }

    cout << result << "\n";

    return 0;
}