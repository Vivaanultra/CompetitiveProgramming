#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Optimize I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> d;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            d.insert(x);
        }

        // Simulate the coloring process
        while (true)
        {
            int current_size = d.size();
            // If the current count (color) is already in the set, that's the final stable color
            if (d.count(current_size))
            {
                cout << current_size << "\n";
                break;
            }
            else
            {
                // Otherwise, add this new color count to the set and continue
                d.insert(current_size);
            }
        }
    }
    return 0;
}