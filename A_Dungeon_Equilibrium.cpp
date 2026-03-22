#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }
    
    int remove_count = 0;
    for (auto const& [val, count] : counts) {
        if (count < val) {
            remove_count += count;
        } else {
            remove_count += (count - val);
        }
    }
    cout << remove_count << endl;
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