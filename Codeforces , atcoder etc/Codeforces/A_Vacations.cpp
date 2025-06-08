#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of vacation days
    int n;
    cin >> n;

    // Create a vector (dynamically sized array) to store the information for each day
    vector<int> a(n);
    // Read the information for each day (0, 1, 2, or 3)
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Create a 2D vector to store the minimum rest days.
    // 'dp[i][j]' will store the minimum rest days up to day 'i'
    // where 'j' represents the activity on day 'i':
    // 0: Rested
    // 1: Did sport
    // 2: Did contest
    vector<vector<int>> dp(n, vector<int>(3, n + 1));

    // Base case: For the first day (day 0)
    if (a[0] == 0) {
        // Gym closed, contest no: Vasya must rest
        dp[0][0] = 1;
    } else if (a[0] == 1) {
        // Gym closed, contest yes: Vasya can rest or do contest
        dp[0][0] = 1; // If Vasya rests on the first day, rest days = 1
        dp[0][2] = 0; // If Vasya does contest on the first day, rest days = 0
    } else if (a[0] == 2) {
        // Gym open, contest no: Vasya can rest or do sport
        dp[0][0] = 1; // If Vasya rests on the first day, rest days = 1
        dp[0][1] = 0; // If Vasya does sport on the first day, rest days = 0
    } else if (a[0] == 3) {
        // Gym open, contest yes: Vasya can rest, do sport, or do contest
        dp[0][0] = 1; // If Vasya rests on the first day, rest days = 1
        dp[0][1] = 0; // If Vasya does sport on the first day, rest days = 0
        dp[0][2] = 0; // If Vasya does contest on the first day, rest days = 0
    }

    // Iterate through the remaining days (from the second day onwards)
    for (int i = 1; i < n; ++i) {
        // For each day, calculate the minimum rest days for each possible activity

        // Case 1: Rest on day 'i'
        // If Vasya rests on day 'i', the number of rest days is 1 (for the current day)
        // plus the minimum rest days from the previous day (no matter what he did)
        dp[i][0] = 1 + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

        // Case 2: Sport on day 'i'
        // Vasya can do sport only if the gym is open (a[i] == 2 or 3)
        if (a[i] == 2 || a[i] == 3) {
            // If Vasya does sport on day 'i', the rest days are the same as the minimum rest days
            // up to the previous day, given that he did NOT do sport yesterday (j != 1)
            dp[i][1] = min(dp[i][1], min(dp[i - 1][0], dp[i - 1][2]));
        }

        // Case 3: Contest on day 'i'
        // Vasya can do contest only if a contest is held (a[i] == 1 or 3)
        if (a[i] == 1 || a[i] == 3) {
            // If Vasya does contest on day 'i', the rest days are the same as the minimum rest days
            // up to the previous day, given that he did NOT do contest yesterday (j != 2)
            dp[i][2] = min(dp[i][2], min(dp[i - 1][0], dp[i - 1][1]));
        }
    }

    // After calculating the minimum rest days for all possibilities up to the last day,
    // the final answer is the minimum of the rest days on the last day
    // whether Vasya rested, did sport, or did a contest.
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;

    return 0;
}