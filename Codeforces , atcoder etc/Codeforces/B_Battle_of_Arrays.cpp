#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // Use Max-Heaps (priority_queue) to efficiently access the largest elements
    priority_queue<long long> pqAlice;
    priority_queue<long long> pqBob;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pqAlice.push(a);
    }

    for (int i = 0; i < m; i++) {
        long long b;
        cin >> b;
        pqBob.push(b);
    }

    // turn = 0 represents Alice, turn = 1 represents Bob
    int turn = 0;

    // The game continues as long as both players have elements
    while (!pqAlice.empty() && !pqBob.empty()) {
        if (turn == 0) {
            // Alice's Turn
            long long x = pqAlice.top(); // Alice's weapon (her max)
            long long y = pqBob.top();   // Bob's target (his max)
            pqBob.pop(); // Remove Bob's max temporarily

            if (y > x) {
                // Bob's element survives but is reduced
                pqBob.push(y - x);
            }
            // If y <= x, it is destroyed (we simply don't push it back)
        } else {
            // Bob's Turn
            long long x = pqBob.top();   // Bob's weapon
            long long y = pqAlice.top(); // Alice's target
            pqAlice.pop(); // Remove Alice's max temporarily

            if (y > x) {
                // Alice's element survives but is reduced
                pqAlice.push(y - x);
            }
            // If y <= x, it is destroyed
        }

        // Switch turn
        turn = 1 - turn;
    }

    // If Bob's array is empty, Alice wins. Otherwise, Bob wins.
    if (pqBob.empty()) {
        cout << "Alice" << "\n";
    } else {
        cout << "Bob" << "\n";
    }
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}