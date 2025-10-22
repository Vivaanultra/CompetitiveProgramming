#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> X(Q);
    for (int i = 0; i < Q; i++) cin >> X[i];

    vector<int> box_count(N, 0);
    vector<int> result(Q);

    for (int i = 0; i < Q; i++) {
        if (X[i] >= 1) {
            box_count[X[i] - 1]++;
            result[i] = X[i];
        } else {
            // Find box with minimum balls and smallest index
            int min_count = box_count[0];
            int min_index = 0;
            for (int j = 1; j < N; j++) {
                if (box_count[j] < min_count) {
                    min_count = box_count[j];
                    min_index = j;
                }
            }
            box_count[min_index]++;
            result[i] = min_index + 1;
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << result[i];
        if (i != Q - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
