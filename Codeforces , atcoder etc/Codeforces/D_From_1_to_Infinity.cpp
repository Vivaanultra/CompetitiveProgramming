#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> p10;
vector<ll> sod_9s;

ll get_sod(ll n) {
    if (n < 0) return 0;
    if (n < 10) return n * (n + 1) / 2;

    string s = to_string(n);
    int d = s.length();
    ll first_digit = n / p10[d - 1];
    ll rem = n % p10[d - 1];

    ll res = 0;
    res += first_digit * sod_9s[d - 1];
    res += (first_digit * (first_digit - 1) / 2) * p10[d - 1];
    res += first_digit * (rem + 1);
    res += get_sod(rem);
    return res;
}

void solve() {
    ll k;
    cin >> k;

    ll total_sum = 0;
    ll d = 1;
    while (true) {
        ll digits_in_block = d * 9 * p10[d - 1];
        if (k <= digits_in_block) {
            break;
        }
        k -= digits_in_block;
        total_sum += get_sod(p10[d] - 1) - get_sod(p10[d - 1] - 1);
        d++;
    }

    ll num_full_numbers = (k - 1) / d;
    ll start_num = p10[d - 1];
    ll end_num = start_num + num_full_numbers - 1;

    if (num_full_numbers > 0) {
        total_sum += get_sod(end_num) - get_sod(start_num - 1);
    }

    ll rem_digits_count = (k - 1) % d + 1;
    ll last_num = start_num + num_full_numbers;
    string last_num_s = to_string(last_num);

    for (int i = 0; i < rem_digits_count; ++i) {
        total_sum += last_num_s[i] - '0';
    }

    cout << total_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    p10.resize(17);
    p10[0] = 1;
    for (int i = 1; i <= 16; ++i) {
        p10[i] = p10[i - 1] * 10;
    }
    sod_9s.resize(17);
    sod_9s[0] = 0;
    for (int i = 1; i <= 16; ++i) {
        sod_9s[i] = i * 45 * p10[i - 1];
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}