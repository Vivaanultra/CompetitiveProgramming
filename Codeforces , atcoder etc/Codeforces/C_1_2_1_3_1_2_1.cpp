#include <bits/stdc++.h>
using namespace std;

vector<int> generate_S(int n) {
    if (n == 1) {
        return {1};
    }

    vector<int> prev_S = generate_S(n - 1);
    vector<int> result = prev_S;
    result.push_back(n);
    result.insert(result.end(), prev_S.begin(), prev_S.end());

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> final_sequence = generate_S(n);

    for (int i = 0; i < final_sequence.size(); ++i) {
        cout << final_sequence[i] << (i == final_sequence.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}