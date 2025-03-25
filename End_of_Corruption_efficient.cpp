#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declare variables for total number of people and king's visits
    int totalpeople, kingvisits;
    
    // Get input for total people and number of times king visits
    cin >> totalpeople >> kingvisits;
    
    // Create a priority queue to automatically keep track of maximum element
    // This is more efficient than using max_element each time
    priority_queue<int> wealth;
    
    // Vector to store the output values when king visits (-1)
    vector<int> kingVisitResults;
    
    // Process each input
    for (int i = 0; i < totalpeople + kingvisits; i++) {
        int x;
        cin >> x;
        
        if (x == -1) {
            // When king visits (-1), get the richest person
            int maxWealth = wealth.top();
            wealth.pop();  // Remove the richest person
            kingVisitResults.push_back(maxWealth);  // Store their wealth
        } else {
            // Add new person's wealth to the queue
            wealth.push(x);
        }
    }
    
    // Print results of each king's visit
    for (int i = 0; i < kingvisits; i++) {
        cout << kingVisitResults[i] << "\n";
    }
    
    return 0;
}