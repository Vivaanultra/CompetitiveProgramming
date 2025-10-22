#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Vector to store shows as {start_time, end_time} pairs
    vector<pair<int, int>> shows(n);
    for (int i = 0; i < n; ++i) {
        cin >> shows[i].first >> shows[i].second;
    }

    // 1. Sort the shows based on their start times.
    // The default sort for a vector of pairs sorts by the first element, which is what we need.
    sort(shows.begin(), shows.end());

    // 2. A min-priority queue to track the end times of shows currently on the TVs.
    // This tells us when each TV will become free. `greater<int>` makes it a min-heap.
    priority_queue<int, vector<int>, greater<int>> tv_free_times;

    // 3. Iterate through all the shows in chronological order of their start times.
    for (int i = 0; i < n; ++i) {
        int start_time = shows[i].first;
        int end_time = shows[i].second;

        // If the priority queue is not empty and the earliest-finishing show
        // ends strictly before the current show starts, that TV is now free.
        if (!tv_free_times.empty() && tv_free_times.top() < start_time) {
            // Remove the finished show's end time from the queue.
            tv_free_times.pop();
        }

        // Assign the current show to a TV by adding its end time to the queue.
        tv_free_times.push(end_time);

        // If the number of shows currently needing a TV is more than 2, it's impossible.
        if (tv_free_times.size() > 2) {
            cout << "NO" << endl;
            return 0;
        }
    }

    // If the loop completes, it means we never needed more than two TVs.
    cout << "YES" << endl;

    return 0;
}