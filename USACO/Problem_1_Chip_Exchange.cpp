#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_req(ll xa, ll trg, ll ca, ll cb) {
    ll rem_a = trg - xa;
    if (rem_a <= 0) return xa;
    
    ll ops = (rem_a + ca - 1) / ca;
    return xa + ops * cb;
}

bool check(ll x, ll trg, ll B, ll ca, ll cb) {
    ll limit = min(x, trg);
  
    ll max_req = get_req(0, trg, ca, cb); 
    max_req = max(max_req, get_req(limit, trg, ca, cb)); 

    ll remd = (trg - 1) % ca;

    ll fp = remd;
    if (fp <= limit) {
        max_req = max(max_req, get_req(fp, trg, ca, cb));
    }
   
    ll diff = (limit - remd) % ca;
    if (diff < 0) diff += ca;
    ll lp = limit - diff;
    
    if (lp >= 0) {
        max_req = max(max_req, get_req(lp, trg, ca, cb));
    }

    return (B + x >= max_req);
}

void solve() {
    ll A, B, ca, cb, fa;
    cin >> A >> B >> ca >> cb >> fa;

    ll trg = fa - A;
    
    
    if (trg <= 0) {
        cout << 0 << "\n";
        return;
    }

    
    ll low = 0, high = 2000000000000000000LL; 
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, trg, B, ca, cb)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}