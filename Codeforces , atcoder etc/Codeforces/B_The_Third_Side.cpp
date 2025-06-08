#include <iostream> // Required for input (std::cin) and output (std::cout)
// No other complex libraries like <vector> or <numeric> are strictly needed
// if we process the sum on the fly.

// This function solves a single test case of the problem.
void solve_test_case() {
    int n; // This variable will store the number of integers in the sequence.
    std::cin >> n; // Read the value of n from standard input.

    long long sum_of_elements = 0; // Use 'long long' for the sum to prevent potential overflow.
                                   // The sum can be up to 2*10^5 * 1000 = 2*10^8.

    // Loop n times to read each integer and add it to the sum.
    for (int i = 0; i < n; ++i) {
        int current_element_value; // Stores the value of the integer read in this iteration.
        std::cin >> current_element_value; // Read the integer.
        sum_of_elements += current_element_value; // Add it to our running total.
    }

    // As derived above:
    // To maximize the final element, at each step of combining p and q into x,
    // we must choose x = p + q - 1.
    // Each such operation reduces the sum of elements in the list by 1.
    // To go from n elements to 1 element, n - 1 operations are needed.
    // So, the final element's value will be: initial_sum - (n - 1).
    // This is equivalent to initial_sum - n + 1.
    // This formula holds even for n=1 (initial_sum - 1 + 1 = initial_sum).
    
    long long max_final_value = sum_of_elements - n + 1;

    std::cout << max_final_value << std::endl; // Print the result for this test case.
}

int main() {
    // These two lines are common C++ optimizations for competitive programming to speed up I/O.
    std::ios_base::sync_with_stdio(false); // Disables synchronization with C-style I/O.
    std::cin.tie(NULL); // Unties std::cin from std::cout, useful when I/O is heavy.

    int number_of_test_cases;
    std::cin >> number_of_test_cases; // Read the number of test cases.

    while (number_of_test_cases--) { // Loop for each test case.
        solve_test_case(); // Call the function to handle one test case.
    }

    return 0; // Indicate successful program termination.
}