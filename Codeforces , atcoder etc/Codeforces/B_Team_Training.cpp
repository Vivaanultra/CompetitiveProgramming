
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        long long x;
        std::cin >> n >> x;

        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end(), std::greater<long long>());

        int strong_teams = 0;
        int current_team_size = 0;

        for (int i = 0; i < n; ++i) {
            current_team_size++;

            if (static_cast<long long>(current_team_size) * a[i] >= x) {
                strong_teams++;
                current_team_size = 0;
            }
        }

        std::cout << strong_teams << "\n";
    }

    return 0;
}
