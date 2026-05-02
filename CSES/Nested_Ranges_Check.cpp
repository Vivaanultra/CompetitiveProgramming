#include <bits/stdc++.h>
using namespace std;

struct Range {
    int l, r, id;
    
    // Sort logic: 
    // 1. Start time Ascending
    // 2. End time Descending (longer ranges first if starts match)
    bool operator<(const Range& other) const {
        if (l == other.l)
            return r > other.r;
        return l < other.l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
    }

    sort(ranges.begin(), ranges.end());

    vector<int> contained(n);
    vector<int> contains(n);

    // Pass 1: Check "Contained By" (Forward)
    // We look for a previous range that ends AFTER current range
    int max_end = 0;
    for (int i = 0; i < n; i++) {
        if (ranges[i].r <= max_end) {
            contained[ranges[i].id] = 1;
        }
        max_end = max(max_end, ranges[i].r);
    }

    // Pass 2: Check "Contains" (Backward)
    // We look for a later range (which starts >= current.l) that ends BEFORE current range
    int min_end = 2e9; // Initialize to infinity
    for (int i = n - 1; i >= 0; i--) {
        if (ranges[i].r >= min_end) {
            contains[ranges[i].id] = 1;
        }
        min_end = min(min_end, ranges[i].r);
    }

    // Print results
    for (int i = 0; i < n; i++) {
        cout << contains[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << contained[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}