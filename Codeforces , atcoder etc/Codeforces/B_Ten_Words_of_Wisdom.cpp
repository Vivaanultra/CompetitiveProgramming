#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int participants;
        cin >> participants;
        vector<tuple<int,int,int>> responses(participants);
        for (int i = 0; i < participants; i++)
        {
            int a, b;
            cin >> a >> b;
            responses[i] = make_tuple(a, b, i + 1);
        }
        int winner = -1;
        int max_quality = -1;
        for (int i = 0; i < participants; i++)
        {
            int a = get<0>(responses[i]);
            int b = get<1>(responses[i]);
            int idx = get<2>(responses[i]);
            if (a <= 10 && b > max_quality)
            {
                max_quality = b;
                winner = idx;
            }
        }
        cout << winner << endl;
    }
    return 0;
}