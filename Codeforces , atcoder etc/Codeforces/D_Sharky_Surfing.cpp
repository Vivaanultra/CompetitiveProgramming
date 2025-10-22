#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Event {
    ll p1, p2;
    int type;

    bool operator<(const Event& other) const {
        if (p1 != other.p1) {
            return p1 < other.p1;
        }
        if (p2 != other.p2) {
            return p2 < other.p2;
        }
        return type < other.type;
    }
};

void solve() {
    ll n, m, L;
    cin >> n >> m >> L;

    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        events.push_back({l, r, 1});
    }
    for (int i = 0; i < m; ++i) {
        ll x, v;
        cin >> x >> v;
        events.push_back({x, v, 0});
    }

    sort(events.begin(), events.end());

    ll k = 1;
    priority_queue<ll> pwr;
    bool possible = true;

    for (const auto& ev : events) {
        ll a = ev.p1;
        ll b = ev.p2;
        int t = ev.type;

        if (t == 0) {
            pwr.push(b);
        } else {
            ll needed_power = b - a + 2;
            while (!pwr.empty() && k < needed_power) {
                k += pwr.top();
                pwr.pop();
            }
            if (k < needed_power) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << m - pwr.size() << endl;
    } else {
        cout << -1 << endl;
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