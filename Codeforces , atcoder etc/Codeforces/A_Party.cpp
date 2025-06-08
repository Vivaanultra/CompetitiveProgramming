#include <iostream>
#include <vector>
#include <algorithm> // For std::max

// It's a common practice in competitive programming to use this namespace
using namespace std;

// Global vectors to store manager information and calculated depths
// Using 1-based indexing for employees (employee IDs 1 to n)
vector<int> managers; // managers[i] stores the manager of employee i
vector<int> depth;    // depth[i] stores the depth of employee i in the hierarchy.
                      // A value of 0 indicates that the depth has not yet been calculated.

// Function to calculate the depth of an employee 'u'
// The depth of an employee with no manager (a root in the hierarchy tree) is 1.
// The depth of any other employee is 1 + the depth of their immediate manager.
// This function uses memoization (stores results in the 'depth' vector) to avoid redundant calculations.
int get_employee_depth(int u) {
    // If the depth for employee 'u' has already been calculated, return the stored value.
    if (depth[u] != 0) {
        return depth[u];
    }

    // If employee 'u' has no manager (managers[u] == -1), they are a root. Their depth is 1.
    if (managers[u] == -1) {
        depth[u] = 1;
        return 1;
    }

    // Otherwise, the depth of employee 'u' is 1 + the depth of their manager.
    // Recursively call get_employee_depth for the manager of 'u' (which is managers[u]).
    depth[u] = get_employee_depth(managers[u]) + 1;
    return depth[u];
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Number of employees
    cin >> n;

    // Resize the global vectors to accommodate 'n' employees (1-indexed).
    // Initialize 'managers' vector (actual values will be read from input).
    // Initialize 'depth' vector with all zeros, signifying that no depths have been calculated yet.
    managers.resize(n + 1);
    depth.resize(n + 1, 0);

    // Read the manager for each employee from 1 to n.
    for (int i = 1; i <= n; ++i) {
        cin >> managers[i];
    }

    int max_depth_in_company = 0;
    // Iterate through all employees to calculate their depth.
    // The 'get_employee_depth' function will ensure each depth is computed only once due to memoization.
    // Keep track of the maximum depth found across all employees.
    for (int i = 1; i <= n; ++i) {
        max_depth_in_company = max(max_depth_in_company, get_employee_depth(i));
    }

    // The minimum number of groups required is equal to the maximum depth in the company hierarchy.
    // This is because all employees in a chain of command of length 'max_depth_in_company'
    // must belong to different groups. Assigning groups based on depth level achieves this minimum.
    cout << max_depth_in_company << endl;

    return 0;
}