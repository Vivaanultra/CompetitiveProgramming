#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Problem base values
    int points[] = {500, 1000, 1500, 2000, 2500};
    
    // Arrays to store inputs
    int m[5]; // Submission times
    int w[5]; // Wrong submissions
    
    // Read submission times
    for (int i = 0; i < 5; i++) {
        cin >> m[i];
    }
    
    // Read wrong submissions
    for (int i = 0; i < 5; i++) {
        cin >> w[i];
    }
    
    // Read hacks
    int hs, hu;
    cin >> hs >> hu;
    
    double totalScore = 0;
    
    // Calculate score for each problem
    for (int i = 0; i < 5; i++) {
        // Calculate the two potential values based on the formula
        // Note: Use 250.0 to ensure floating point division
        double calculatedScore = (1.0 - m[i] / 250.0) * points[i] - 50 * w[i];
        double minScore = 0.3 * points[i];
        
        // Add the maximum of the two to the total
        totalScore += max(minScore, calculatedScore);
    }
    
    // Add successful hacks (+100) and subtract unsuccessful hacks (-50)
    totalScore += (hs * 100);
    totalScore -= (hu * 50);
    
    // Output the result cast to integer
    cout << (int)totalScore << endl;
    
    return 0;
}