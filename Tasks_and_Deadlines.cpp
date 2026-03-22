#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

   
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

   
    sort(v.begin(), v.end());

    ll current_time = 0;
    ll reward = 0;

    for(int i = 0; i < n; i++) {
        current_time += v[i].first;
        reward += v[i].second - current_time;
    }

    cout << reward << endl;

    return 0;
}