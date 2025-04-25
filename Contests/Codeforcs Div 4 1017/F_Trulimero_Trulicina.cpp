#include <iostream> // This line includes the iostream library, which provides input and output functionalities like reading from the console (std::cin) and writing to the console (std::cout).
#include <vector>   // This line includes the vector library, which allows you to use dynamic arrays (std::vector).
#include <numeric>  // This line includes the numeric library, which provides various numerical algorithms (though it's not strictly necessary in this version of the code).

// This function calculates the Greatest Common Divisor (GCD) of two integers 'a' and 'b' using the Euclidean algorithm.
int gcd(int a, int b) {
    // The while loop continues as long as 'b' is not zero.
    while (b) {
        // The modulo operator (%) calculates the remainder when 'a' is divided by 'b'.
        // This remainder is then assigned back to 'a'.
        a %= b;
        // This line swaps the values of 'a' and 'b'.
        // After the swap, the old value of 'b' (which was the remainder) is now in 'a',
        // and the old value of 'a' is now in 'b'.
        std::swap(a, b);
    }
    // When the loop finishes (i.e., 'b' becomes 0), the GCD is stored in 'a'.
    return a;
}

int main() {
    int t; // Declare an integer variable 't' to store the number of test cases.
    std::cin >> t; // Read the number of test cases from the input.
    // This while loop will iterate 't' times, processing each test case.
    while (t--) {
        int n, m, k; // Declare integer variables 'n', 'm', and 'k' for the dimensions of the grid and the number of distinct integers.
        std::cin >> n >> m >> k; // Read the values of 'n', 'm', and 'k' from the input for the current test case.
        // Create a 2D vector named 'grid' of size 'n' rows and 'm' columns to store the integers for the grid.
        // Each element of the grid is initially an integer.
        std::vector<std::vector<int>> grid(n, std::vector<int>(m));

        // This condition checks if either 'n' is divisible by 'k' or 'm' is divisible by 'k'.
        if (n % k == 0 || m % k == 0) {
            // If either dimension is divisible by 'k', we can use a simpler pattern to fill the grid.
            // This nested loop iterates through each row of the grid (from 0 to n-1).
            for (int i = 0; i < n; ++i) {
                // This nested loop iterates through each column of the current row (from 0 to m-1).
                for (int j = 0; j < m; ++j) {
                    // This line assigns a value to the current cell in the grid at row 'i' and column 'j'.
                    // The value is calculated as (i + j) % k + 1.
                    // (i + j) % k will give a remainder between 0 and k-1.
                    // Adding 1 to this remainder ensures that the values are between 1 and k, inclusive.
                    // This pattern ensures that no two adjacent cells have the same value when either n or m is divisible by k.
                    grid[i][j] = (i + j) % k + 1;
                }
            }
        } else {
            // If neither 'n' nor 'm' is divisible by 'k', we need a slightly more complex pattern.
            // Calculate the greatest common divisor (GCD) of 'n' and 'k'.
            int k1 = gcd(n, k);
            // Calculate 'k2' by dividing 'k' by 'k1'. This ensures that k1 * k2 = k.
            int k2 = k / k1;
            // This nested loop iterates through each row of the grid (from 0 to n-1).
            for (int i = 0; i < n; ++i) {
                // This nested loop iterates through each column of the current row (from 0 to m-1).
                for (int j = 0; j < m; ++j) {
                    // This line assigns a value to the current cell in the grid at row 'i' and column 'j'.
                    // The value is calculated as (i % k1) * k2 + (j % k2) + 1.
                    // (i % k1) will give a remainder between 0 and k1-1.
                    // Multiplying this by k2 gives a value in the range [0, k1*k2 - k2] or [0, k - k2].
                    // (j % k2) will give a remainder between 0 and k2-1.
                    // Adding these together and then adding 1 ensures that the values are between 1 and k, inclusive,
                    // and that no two adjacent cells have the same integer.
                    grid[i][j] = (i % k1) * k2 + (j % k2) + 1;
                }
            }
        }

        // This nested loop iterates through the generated grid to print its contents.
        for (int i = 0; i < n; ++i) {
            // This nested loop iterates through each element in the current row.
            for (int j = 0; j < m; ++j) {
                // Print the value of the current cell.
                std::cout << grid[i][j];
                // If it's not the last element in the row, print a space to separate the numbers.
                if (j == m - 1) {
                    std::cout << ""; // If it's the last element, print nothing (to avoid trailing space).
                } else {
                    std::cout << " "; // Otherwise, print a space.
                }
            }
            // After printing all elements in a row, print a newline character to move to the next line.
            std::cout << std::endl;
        }
    }
    // This indicates that the main function has executed successfully.
    return 0;
}