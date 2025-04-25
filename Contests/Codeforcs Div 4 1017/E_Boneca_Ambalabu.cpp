  #include <bits/stdc++.h>
  using namespace std;
  typedef long long ll;

  void solve() {
      int n;
      cin >> n;
      vector<ll> a(n);
      for(int i = 0; i < n; i++) {
          cin >> a[i];
      }
    
      ll maxSum = 0;
      vector<int> bits(30, 0);
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < 30; j++) {
              if(a[i] & (1LL << j)) bits[j]++;
          }
      }
    
      for(int k = 0; k < n; k++) {
          ll currentSum = 0;
          for(int j = 0; j < 30; j++) {
              ll bit = (a[k] & (1LL << j)) ? 1 : 0;
              currentSum += (1LL << j) * (bit * (n - bits[j]) + (!bit) * bits[j]);
          }
          maxSum = max(maxSum, currentSum);
      }
      cout << maxSum << "\n";
  }

  int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
    
      int t;
      cin >> t;
      while(t--) {
          solve();
      }
      return 0;
  }
