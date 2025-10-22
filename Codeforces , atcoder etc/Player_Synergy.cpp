#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Must select at least one player. If only one, the answer is their synergy.
    if (n == 1) {
        long long val;
        cin >> val;
        cout << val;
        return 0;
    }

    vector<long long> pos; // To store positive synergies
    vector<long long> neg; // To store negative synergies
    int zero_count = 0;

    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (val > 0) {
            pos.push_back(val);
        } else if (val < 0) {
            neg.push_back(val);
        } else {
            zero_count++;
        }
    }
    
    // Edge Case: No way to make a positive product.
    // This happens if we have no positive numbers and at most one negative number.
    if (pos.empty() && neg.size() <= 1) {
        // If a zero exists, we can pick it for a synergy of 0, which is better than being negative.
        if (zero_count > 0) {
            cout << 0;
        } else {
            // If no zeros and only one negative, that's our only choice. If no players, problem statement says we pick at least one.
            // But with n > 1 this case won't happen. If n=1 it is handled above.
            // This will only be reached if there is one negative number and nothing else.
            if(neg.size() == 1) {
                cout << neg[0];
            } else { // All zeros
                cout << 0;
            }
        }
        return 0;
    }

    long long product = 1;

    // Multiply all positive numbers
    for (long long p : pos) {
        product *= p;
    }

    // Multiply all negative numbers
    for (long long ng : neg) {
        product *= ng;
    }

    // If the product is negative, it means we had an odd number of negative players.
    // To maximize the product, we must make it positive by removing one negative number.
    // We remove the one with the smallest absolute value (the one closest to zero).
    if (product < 0) {
        sort(neg.begin(), neg.end());
        product /= neg.back(); // Divide by the largest negative number
    }

    cout << product;

    return 0;
}