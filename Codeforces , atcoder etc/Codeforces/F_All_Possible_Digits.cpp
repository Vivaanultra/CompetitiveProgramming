#include <bits/stdc++.h>

using namespace std;

long long find_largest_missing(const set<long long>& seen, long long start_point) {
    if (start_point < 0) {
        return -1;
    }
    long long target = start_point;
    auto it = seen.upper_bound(start_point);

    if (it == seen.begin()) {
        return start_point;
    }
    it--;

    while (true) {
        if (*it == target) {
            if (target == 0) {
                target = -1;
                break;
            }
            target--;
            if (it == seen.begin()) {
                break;
            }
            it--;
        } else {
            break;
        }
    }
    return target;
}

void solve() {
    int n;
    long long p;
    cin >> n >> p;
    vector<long long> a(n);
    set<long long> seen;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        seen.insert(a[i]);
    }

    long long last_digit = a.back();

    long long missing_below = find_largest_missing(seen, last_digit - 1);

    if (missing_below < 0) {
        long long target = find_largest_missing(seen, p - 1);
        if (target < last_digit) {
            cout << 0 << endl;
        } else {
            cout << target - last_digit << endl;
        }
    } else {
        long long ops_to_carry = p - last_digit;
        
        vector<long long> num = a;
        long long carry = ops_to_carry;
        for (int i = n - 1; i >= 0; --i) {
            if (carry == 0) break;
            long long sum = num[i] + carry;
            num[i] = sum % p;
            carry = sum / p;
        }
        while (carry > 0) {
            num.insert(num.begin(), carry % p);
            carry /= p;
        }
        
        for(long long digit : num) {
            seen.insert(digit);
        }
        
        long long final_target = find_largest_missing(seen, last_digit - 1);
        
        long long total_ops = ops_to_carry;
        if (final_target >= 0) {
            total_ops += final_target;
        }
        
        cout << total_ops << endl;
    }
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
