#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string base_pattern = "";
    for (int i = 0; i < k; ++i) {
        base_pattern += (char)('a' + i);
        for (int j = i + 1; j < k; ++j) {
            base_pattern += (char)('a' + i);
            base_pattern += (char)('a' + j);
        }
    }

    string final_string = "";
    for (int i = 0; i < n; ++i) {
        final_string += base_pattern[i % base_pattern.length()];
    }

    cout << final_string << endl;

    return 0;
}