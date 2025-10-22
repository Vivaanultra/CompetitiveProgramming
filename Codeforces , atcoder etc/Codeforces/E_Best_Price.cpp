#include <bits/stdc++.h>
 
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<pair<int, int>> ev;
    for (int i = 0; i < n; ++i) {
      ev.emplace_back(a[i], 1);
      ev.emplace_back(b[i], 2);
    }
    sort(ev.begin(), ev.end());
    long long ans = 0;
    int cnt = n, bad = 0;
    for (int i = 0; i < 2 * n;) {
      auto [x, y] = ev[i];
      if (bad <= k) ans = max(ans, x * 1LL * cnt);
      while (i < 2 * n && ev[i].first == x) {
        bad += (ev[i].second == 1);
        bad -= (ev[i].second == 2);
        cnt -= (ev[i].second == 2);
        ++i;
      }
    }
    cout << ans << '\n';
  }
}