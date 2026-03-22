#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    if (!(cin >> n >> h)) return 0;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int k;
    cin >> k;
    vector<int> is_wc(n + 1, 0);
    for (int i = 0; i < k; ++i) {
        int s;
        cin >> s;
        is_wc[s] = 1;
    }

    set<pair<long long, int>> hand_wcs;
    set<pair<long long, int>> hand_nwcs;
    queue<int> draw_q;

    for (int i = 1; i <= h; ++i) {
        if (is_wc[i]) {
            hand_wcs.insert({a[i], i});
        } else {
            hand_nwcs.insert({a[i], i});
        }
    }

    for (int i = h + 1; i <= n; ++i) {
        draw_q.push(i);
    }

    int q_size = n - h;
    int L = q_size + 1;

    vector<long long> cycle_costs(L);
    vector<int> cycle_wcs(L);

    for (int step = 0; step < L; ++step) {
        pair<long long, int> played;
        if (!hand_wcs.empty()) {
            played = *hand_wcs.begin();
            hand_wcs.erase(hand_wcs.begin());
        } else {
            played = *hand_nwcs.begin();
            hand_nwcs.erase(hand_nwcs.begin());
        }

        cycle_costs[step] = played.first;
        cycle_wcs[step] = is_wc[played.second];

        draw_q.push(played.second);
        int drawn = draw_q.front();
        draw_q.pop();

        if (is_wc[drawn]) {
            hand_wcs.insert({a[drawn], drawn});
        } else {
            hand_nwcs.insert({a[drawn], drawn});
        }
    }

    vector<long long> pref_costs(L);
    vector<int> pref_wcs(L);
    pref_costs[0] = cycle_costs[0];
    pref_wcs[0] = cycle_wcs[0];

    for (int i = 1; i < L; ++i) {
        pref_costs[i] = pref_costs[i - 1] + cycle_costs[i];
        pref_wcs[i] = pref_wcs[i - 1] + cycle_wcs[i];
    }

    long long sum_costs = pref_costs[L - 1];
    long long sum_wcs = pref_wcs[L - 1];

    int num_queries;
    cin >> num_queries;

    long long ElsieNumber = 0;

    while (num_queries--) {
        long long t;
        cin >> t;
        
        long long full_cycles = t / sum_costs;
        long long rem_t = t % sum_costs;

        ElsieNumber = full_cycles * sum_wcs;

        if (rem_t > 0) {
            int idx = upper_bound(pref_costs.begin(), pref_costs.end(), rem_t) - pref_costs.begin() - 1;
            if (idx >= 0) {
                ElsieNumber += pref_wcs[idx];
            }
        }
        cout << ElsieNumber << "\n";
    }

    return 0;
}