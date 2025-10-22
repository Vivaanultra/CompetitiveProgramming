#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

// Using competitive programming practices as requested
#include <bits/stdc++.h>
using namespace std;

// Use long long for safety with LCM calculations
using ll = long long;

// Standard Euclidean algorithm to find the Greatest Common Divisor
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Function to find the Least Common Multiple
ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    // (a * b) / gcd(a, b) can overflow, so do division first
    return (a / gcd(a, b)) * b;
}

// Function to find the period of a string
int find_period(const string& s) {
    int n = s.length();
    // The period must be a divisor of the string length
    for (int p = 1; p <= n; ++p) {
        if (n % p == 0) {
            bool is_periodic = true;
            // Check if the string is just its prefix of length p repeated
            for (int i = p; i < n; ++i) {
                if (s[i] != s[i - p]) {
                    is_periodic = false;
                    break;
                }
            }
            if (is_periodic) {
                return p; // Return the first (smallest) period found
            }
        }
    }
    return n; // Should not be reached for non-empty strings
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        // Convert to 0-based indexing for easier use in C++
        p[i]--;
    }

    vector<bool> visited(n, false);
    ll total_lcm = 1;

    // Iterate through all indices to find all cycles
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            // Found the start of a new, unvisited cycle
            string cycle_str = "";
            int current_node = i;
            
            // Traverse the cycle
            while (!visited[current_node]) {
                visited[current_node] = true;
                cycle_str += s[current_node];
                current_node = p[current_node];
            }
            
            // Find the period of this cycle's string
            int period = find_period(cycle_str);

            // Update the total LCM with this cycle's period
            total_lcm = lcm(total_lcm, period);
        }
    }

    cout << total_lcm << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}