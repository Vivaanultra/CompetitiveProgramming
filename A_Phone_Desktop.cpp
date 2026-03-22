#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        int screens = (y + 1) / 2;
        int remaining_space = (screens * 15) - (y * 4);

        x -= remaining_space;
        if (x > 0) {
            screens += (x + 14) / 15;
        }

        cout << screens << endl;
    }
    return 0;
}