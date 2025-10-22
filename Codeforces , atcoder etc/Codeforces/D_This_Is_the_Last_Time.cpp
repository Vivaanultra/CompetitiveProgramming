//the codeforces editorial thinks that this is some simple greedy problem but I disagree
//what if the code skips over the best possible real values due to some previous one overshooting it's L and R?
//this looks more like a DP problem, I am pasting the editorial solution to take a look later
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n,k;
    cin >> n >> k;
    pair <int,pair <int,int> > p[n + 1];
    for(int i = 1;i <= n;i++) cin >> p[i].first >> p[i].second.first >> p[i].second.second;
    sort(p + 1,p + n + 1);
    int cur = k;
    for(int i = 1;i <= n;i++) {
      if(p[i].first > cur) break;
      cur = max(cur,p[i].second.second);
    }
    cout << cur << endl;
  }
}