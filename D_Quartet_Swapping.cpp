#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree (Binary Indexed Tree) for O(N log N) inversion counting
struct FenwickTree {
    int size;
    vector<int> tree;

    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void add(int index, int val) {
        for (; index <= size; index += index & -index) {
            tree[index] += val;
        }
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }
};

long long count_inversions(const vector<int>& arr) {
    if (arr.empty()) return 0;
    int max_val = 0;
    for (int x : arr) max_val = max(max_val, x);
    
    FenwickTree ft(max_val);
    long long inv_count = 0;
    // Iterate backwards to count how many smaller elements appeared previously
    for (int i = arr.size() - 1; i >= 0; --i) {
        inv_count += ft.query(arr[i] - 1);
        ft.add(arr[i], 1);
    }
    return inv_count;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> odds, evens;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // 1-based index logic
        if ((i + 1) % 2 != 0) { 
            odds.push_back(a[i]);
        } else {
            evens.push_back(a[i]);
        }
    }

    // Check inversion parity
    long long odd_inv = count_inversions(odds);
    long long even_inv = count_inversions(evens);

    // Ideally, we want both sorted
    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    // If parities don't match, we are forced to swap one pair.
    // We swap the last two elements of the list that ends at index n 
    // to keep the error as far right as possible.
    if (odd_inv % 2 != even_inv % 2) {
        if (n % 2 != 0) {
            // n is odd, so the last element of the array belongs to 'odds'
            swap(odds[odds.size() - 1], odds[odds.size() - 2]);
        } else {
            // n is even, so the last element of the array belongs to 'evens'
            swap(evens[evens.size() - 1], evens[evens.size() - 2]);
        }
    }

    // Merge and print
    int o = 0, e = 0;
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 2 != 0) {
            cout << odds[o++] << " ";
        } else {
            cout << evens[e++] << " ";
        }
    }
    cout << "\n";
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