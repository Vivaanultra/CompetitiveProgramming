#include <bits/stdc++.h>

using namespace std;

// Calculates the maximum number of words for ONE potential dominant character
int solveForChar(char dominant_char, int n, const vector<string>& words) {
    vector<int> scores;
    for (const auto& word : words) {
        int dominant_count = 0;
        for (char letter : word) {
            if (letter == dominant_char) {
                dominant_count++;
            }
        }
        int other_count = word.length() - dominant_count;
        scores.push_back(dominant_count - other_count);
    }

    // Sort scores from highest to lowest
    sort(scores.begin(), scores.end(), greater<int>());

    // Greedily add words as long as the story remains "interesting"
    long long current_sum = 0;
    int words_count = 0;
    for (int score : scores) {
        current_sum += score;
        if (current_sum > 0) {
            words_count++;
        } else {
            // If the sum is not positive, we can't add any more words
            break;
        }
    }
    return words_count;
}

void solve() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    int max_words = 0;
    for (char c : {'a', 'b', 'c', 'd', 'e'}) {
        max_words = max(max_words, solveForChar(c, n, words));
    }

    cout << max_words << endl;
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