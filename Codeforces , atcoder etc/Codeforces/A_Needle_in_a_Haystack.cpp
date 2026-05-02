#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string s, t;
    if (!(cin >> s >> t)) return;

    vector<int> count_s(26, 0);
    vector<int> count_t(26, 0);

    for (char c : s) count_s[c - 'a']++;
    for (char c : t) count_t[c - 'a']++;

    // Calculate available "waste" characters (excess chars in t)
    vector<int> waste(26, 0);
    for (int i = 0; i < 26; ++i) {
        if (count_t[i] < count_s[i]) {
            cout << "Impossible" << endl;
            return;
        }
        waste[i] = count_t[i] - count_s[i];
    }

    int n = s.length();
    // keep_equal[i] stores whether we should print waste characters equal to s[i]
    // immediately before s[i].
    vector<bool> keep_equal(n);
    
    // Base case: For the last character, it doesn't matter (lexicographically identical locally),
    // so we default to true to clear the buffer.
    keep_equal[n - 1] = true; 

    // Iterate backwards to determine behavior based on the next different character
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] < s[i+1]) {
            // Sequence is increasing (e.g., 'a' then 'b'). 
            // Printing waste 'a's before s[i] keeps them before the larger 'b'.
            keep_equal[i] = true;
        } else if (s[i] > s[i+1]) {
            // Sequence is decreasing (e.g., 'b' then 'a').
            // We should hold waste 'b's to put them after the smaller 'a'.
            keep_equal[i] = false;
        } else {
            // Characters are equal, inherit decision from the next position
            keep_equal[i] = keep_equal[i+1];
        }
    }

    string result = "";
    // Reserve memory to prevent reallocations (optional optimization)
    result.reserve(t.length());
    
    int waste_ptr = 0; // Points to the smallest available waste character (0='a', 25='z')

    for (int i = 0; i < n; ++i) {
        int s_char_idx = s[i] - 'a';

        // Try to insert waste characters before the current s[i]
        while (waste_ptr < 26) {
            // If no waste of this character exists, move to next
            if (waste[waste_ptr] == 0) {
                waste_ptr++;
                continue;
            }

            // Case 1: Waste is strictly smaller. ALWAYS print to minimize string.
            if (waste_ptr < s_char_idx) {
                result += (char)('a' + waste_ptr);
                waste[waste_ptr]--;
            } 
            // Case 2: Waste is equal. Check precomputed logic.
            else if (waste_ptr == s_char_idx) {
                if (keep_equal[i]) {
                    result += (char)('a' + waste_ptr);
                    waste[waste_ptr]--;
                } else {
                    // Logic says wait: save this waste for later to expose a smaller neighbor in s
                    break; 
                }
            } 
            // Case 3: Waste is larger. Never print before a smaller s[i].
            else {
                break;
            }
        }
        
        // Print the required character from the subsequence s
        result += s[i];
    }

    // Append any remaining waste characters sorted at the end
    for (int i = 0; i < 26; ++i) {
        while (waste[i] > 0) {
            result += (char)('a' + i);
            waste[i]--;
        }
    }

    cout << result << endl;
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}