#include <bits/stdc++.h>

using namespace std;

struct Song {
    long long t, b;
};

bool compareSongs(const Song& s1, const Song& s2) {
    if (s1.b != s2.b) {
        return s1.b > s2.b;
    }
    return s1.t > s2.t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    vector<Song> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i].t >> songs[i].b;
    }

    sort(songs.begin(), songs.end(), compareSongs);

    long long max_pleasure = 0;
    long long current_len_sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> top_k_lengths;

    for (int i = 0; i < n; ++i) {
        long long current_t = songs[i].t;
        long long current_b = songs[i].b;

        top_k_lengths.push(current_t);
        current_len_sum += current_t;

        if (top_k_lengths.size() > k) {
            current_len_sum -= top_k_lengths.top();
            top_k_lengths.pop();
        }

        max_pleasure = max(max_pleasure, current_len_sum * current_b);
    }

    cout << max_pleasure << "\n";

    return 0;
}