#include <iostream>

// Function to check if the scores for a single half are valid
bool is_half_possible(int goals_team1, int goals_team2) {
    if (goals_team1 > 2 * (goals_team2 + 1)) {
        return false;
    }
    if (goals_team2 > 2 * (goals_team1 + 1)) {
        return false;
    }
    return true;
}

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    // Check if the first half score is possible
    bool first_half_ok = is_half_possible(a, b);

    // Calculate goals scored in the second half
    int second_half_c = c - a;
    int second_half_d = d - b;

    // Check if the second half score is possible
    bool second_half_ok = is_half_possible(second_half_c, second_half_d);

    if (first_half_ok && second_half_ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}