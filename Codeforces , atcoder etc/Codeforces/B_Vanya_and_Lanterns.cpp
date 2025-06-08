#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int lanterns, length;
    cin >> lanterns >> length;
    vector<int> positions(lanterns);
    for (int i = 0; i < lanterns; ++i) {
        cin >> positions[i];
    }
    sort(positions.begin(), positions.end());
    double max_distance = positions[0];
    for(int i = 0; i < positions.size() -1; i++)
    {
        double distance = (positions[i + 1] - positions[i]) / 2.0;
        max_distance = max(max_distance, distance);
    }
    double last_distance = length - positions[lanterns - 1];
    max_distance = max(max_distance, last_distance);
    cout << fixed << setprecision(10) << max_distance << endl;
}