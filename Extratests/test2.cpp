#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

string testOutput(bool useTie, bool useEndl) {
    const int iterations = 10000;
    
    // If useTie is true, disable the tie between cin and cout and unsync C I/O.
    if (useTie) {
        cin.tie(0);
        ios_base::sync_with_stdio(false);
    }
    
    auto start = high_resolution_clock::now();
    
    for (int i = 0; i < iterations; i++) {
        if (useEndl) {
            cout << i << endl;
        } else {
            cout << i << '\n';
        }
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    stringstream result;
    result << fixed << setprecision(3);
    result << "Time taken with" 
           << (useTie ? " cin.tie(0)" : "out cin.tie(0)")
           << " using " 
           << (useEndl ? "endl" : "\\n")
           << ": " 
           << duration.count() / 1000.0 
           << " milliseconds";
    return result.str();
}

int main() {
    vector<string> results;
    cout << "Testing all combinations of cin.tie(0) and endl vs \\n\n\n";
    
    // Test all combinations:
    // 1. without cin.tie(0), with '\n'
    results.push_back(testOutput(false, false));
    // 2. without cin.tie(0), with endl
    results.push_back(testOutput(false, true));
    // 3. with cin.tie(0), with '\n'
    results.push_back(testOutput(true, false));
    // 4. with cin.tie(0), with endl
    results.push_back(testOutput(true, true));
    
    cout << "\nResults:\n";
    for (const auto &result : results) {
        cout << result << '\n';
    }
    
    return 0;
}
