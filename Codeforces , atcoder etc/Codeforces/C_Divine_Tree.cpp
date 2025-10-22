#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	int tc; cin >> tc;
	while(tc--) {
		int n; long long m; cin >> n >> m;
		if((m < n) || (m > (long long)n*(n+1)/2)) {
			cout << "-1\n";
			continue;
		}
 
		vector<int> vals(n);
		for(int i = 0; i < n; i++) {
			vals[i] = i+1;
		}
		long long rem = (long long)n*(n+1)/2 - m;
		for(int i = n-1; i >= 0; i--) {
			if(rem <= vals[i]-1) {
				vals[i] -= rem;
				rem = 0;
			}
			else {
				rem -= (vals[i] - 1);
				vals[i] = 1;
			}
			if(rem <= 0) break;
		}
 
		int root = *max_element(vals.begin(), vals.end());
 
		cout << root << "\n";
 
		for(int i = 0; i < n; i++) {
			if(vals[i] == i + 1) {
				if(i + 1 == root) continue;
				cout << i + 1 << " " << root << "\n";
			}
			else {
				cout << i + 1 << " " << vals[i] << "\n";
			}
		}
	}
 
	return 0;
}