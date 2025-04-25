#include <iostream> // For input (cin) and output (cout)
#include <vector>   // To use the vector data structure
#include <algorithm> // For using min_element and max_element
#include <limits>   // Required if finding min/max manually with initial values
using namespace std;
// Using long long because beauty levels can be up to 10^9
using ll = long long;

int main() {
        // Optimize input/output operations for speed
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int t; // Variable to store the number of test cases
        cin >> t; // Read the number of test cases

        while (t--) { // Loop t times for each test case
            int n; // Variable to store the number of sheep
            cin >> n; // Read the number of sheep

            // Create a vector to store the beauty levels.
            // Use long long as the values can be large.
            vector<ll> a(n);

            // Read the beauty levels for the n sheep
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }

            // Find the minimum element in the vector 'a'
            // min_element returns an iterator, so we dereference it (*) to get the value
            ll min_beauty = *min_element(a.begin(), a.end());

            // Find the maximum element in the vector 'a'
            // max_element returns an iterator, so we dereference it (*) to get the value
            ll max_beauty = *max_element(a.begin(), a.end());

            // Calculate the maximum possible pleasure, which is the difference
            // between the maximum and minimum initial beauty levels.
            ll max_pleasure = max_beauty - min_beauty;

            // Print the result for the current test case, followed by a newline
            cout << max_pleasure << "\n";
        }

        return 0; // Indicate successful program execution
}