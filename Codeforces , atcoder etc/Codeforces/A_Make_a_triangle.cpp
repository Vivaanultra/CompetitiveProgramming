#include <iostream>
#include <algorithm> // Required for std::sort
#include <vector>

using namespace std;

int main() {
    // We use an array (or vector) to easily sort the three inputs
    int sticks[3];
    
    // Read the input
    if (cin >> sticks[0] >> sticks[1] >> sticks[2]) {
        
        // Sort the sticks in ascending order
        // After sorting: sticks[0] is smallest, sticks[2] is largest
        sort(sticks, sticks + 3);
        
        int a = sticks[0];
        int b = sticks[1];
        int c = sticks[2];
        
        // Check if they already form a valid triangle
        // The sum of the two smaller sides must be > the largest side
        if (a + b > c) {
            cout << 0 << endl;
        } else {
            // Calculate how much we need to add to (a + b) to make it equal to (c + 1)
            // Target: a + b + minutes = c + 1
            // minutes = c + 1 - a - b
            int minutes = (c + 1) - (a + b);
            cout << minutes << endl;
        }
    }
    
    return 0;
}