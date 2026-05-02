#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_pos_at_time(ll c, ll t) {
    ll cur_t = c;
    ll pos = c;

    while (cur_t < t) {
        ll next_t = cur_t + 1;
        ll k = next_t / 2; 
        
        if (pos == 0) {
            
            pos = k;
            cur_t++;
        } else if (pos > k) {
            ll target = 2 * pos - 1;
            if (target > t) target = t;
            
            if (target <= cur_t) cur_t++; 
            else cur_t = target;
        } else { 
            ll jump = pos;
            if (cur_t + jump > t) jump = t - cur_t;
            
            pos -= jump;
            cur_t += jump;
        }
    }
    return pos;
}
ll get_cow_at_pos(ll x, ll t) {
    ll cur_t = t;
    ll pos = x;
    while (pos <= cur_t / 2) {
        ll k = cur_t / 2;
        if (pos == k) { 
            pos = 0;
            cur_t--;
        } else {  
            ll delta = (cur_t - 2 * pos) / 3;
            
            if (delta == 0) delta = 1;
            
            pos += delta;
            cur_t -= delta;
        }
    } 
    return pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (cin >> Q) {
        while (Q--) {
            int type;
            ll a, b;
            cin >> type >> a >> b;
            if (type == 1) {
                cout << get_pos_at_time(a, b) << "\n";
            } else {
                cout << get_cow_at_pos(a, b) << "\n";
            }
        }
    }
    return 0;
}