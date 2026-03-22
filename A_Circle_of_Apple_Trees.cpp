#include <iostream>
#include <vector>
#include <set> // Using a set to store unique elements

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    
    // std::set automatically handles storing only unique values.
    std::set<int> unique_beauties;
    
    for (int i = 0; i < n; ++i) {
        int beauty;
        std::cin >> beauty;
        // Insert the beauty value into the set
        unique_beauties.insert(beauty);
    }
    
    // The size of the set is the count of unique beauty values,
    // which is the maximum number of apples we can eat.
    std::cout << unique_beauties.size() << "\n";
}

int main() {
    // Optimize C++ input/output operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t; // Read the number of test cases
    
    while (t--) {
        solve(); // Solve each test case
    }
    
    return 0;
}