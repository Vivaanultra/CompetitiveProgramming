#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Point {
    long long x, y;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);
    std::vector<long long> all_x_coords(n), all_y_coords(n);
    std::map<long long, int> x_counts, y_counts;

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
        all_x_coords[i] = points[i].x;
        all_y_coords[i] = points[i].y;
        x_counts[points[i].x]++;
        y_counts[points[i].y]++;
    }

    if (n == 0) { // Should not happen based on constraints 1 <= n
        std::cout << 0 << std::endl;
        return;
    }
    if (n == 1) {
        std::cout << 1 << std::endl;
        return;
    }

    std::vector<long long> distinct_x_overall = all_x_coords;
    std::sort(distinct_x_overall.begin(), distinct_x_overall.end());
    distinct_x_overall.erase(std::unique(distinct_x_overall.begin(), distinct_x_overall.end()), distinct_x_overall.end());

    std::vector<long long> distinct_y_overall = all_y_coords;
    std::sort(distinct_y_overall.begin(), distinct_y_overall.end());
    distinct_y_overall.erase(std::unique(distinct_y_overall.begin(), distinct_y_overall.end()), distinct_y_overall.end());

    long long overall_min_x_orig = distinct_x_overall[0];
    long long overall_max_x_orig = distinct_x_overall.back();
    long long overall_min_y_orig = distinct_y_overall[0];
    long long overall_max_y_orig = distinct_y_overall.back();

    // Cost_A: No monster is moved
    long long min_total_cost = (overall_max_x_orig - overall_min_x_orig + 1) * 
                               (overall_max_y_orig - overall_min_y_orig + 1);

    // Cost_B: One monster is moved
    for (int i = 0; i < n; ++i) { // Iterate through each point to consider moving it
        long long current_point_x = points[i].x;
        long long current_point_y = points[i].y;

        // Calculate bounding box for the other n-1 points (S')
        long long min_x_S_prime, max_x_S_prime, min_y_S_prime, max_y_S_prime;
        int num_remaining_points = n - 1;

        // Determine X-span for S'
        if (distinct_x_overall.size() == 1) { // All original points on a vertical line
            min_x_S_prime = distinct_x_overall[0];
            max_x_S_prime = distinct_x_overall[0];
        } else { 
            min_x_S_prime = overall_min_x_orig;
            if (current_point_x == overall_min_x_orig && x_counts.at(overall_min_x_orig) == 1) {
                min_x_S_prime = distinct_x_overall[1]; 
            }
            max_x_S_prime = overall_max_x_orig;
            if (current_point_x == overall_max_x_orig && x_counts.at(overall_max_x_orig) == 1) {
                max_x_S_prime = distinct_x_overall[distinct_x_overall.size() - 2]; 
            }
        }

        // Determine Y-span for S'
        if (distinct_y_overall.size() == 1) { // All original points on a horizontal line
            min_y_S_prime = distinct_y_overall[0];
            max_y_S_prime = distinct_y_overall[0];
        } else { 
            min_y_S_prime = overall_min_y_orig;
            if (current_point_y == overall_min_y_orig && y_counts.at(overall_min_y_orig) == 1) {
                min_y_S_prime = distinct_y_overall[1]; 
            }
            max_y_S_prime = overall_max_y_orig;
            if (current_point_y == overall_max_y_orig && y_counts.at(overall_max_y_orig) == 1) {
                max_y_S_prime = distinct_y_overall[distinct_y_overall.size() - 2];
            }
        }
        
        long long W_S_prime = max_x_S_prime - min_x_S_prime + 1;
        long long H_S_prime = max_y_S_prime - min_y_S_prime + 1;
        long long Area_S_prime = W_S_prime * H_S_prime;
        long long current_loop_cost;

        if (num_remaining_points == 0) { // Should have been caught by n=1 case
            current_loop_cost = 1; 
        } else if (Area_S_prime == num_remaining_points) { // Dense packing for S'
            current_loop_cost = std::min(W_S_prime * (H_S_prime + 1), (W_S_prime + 1) * H_S_prime);
        } else { // Sparse packing for S', k_new can fit inside B(S')
            current_loop_cost = Area_S_prime;
        }
        
        min_total_cost = std::min(min_total_cost, current_loop_cost);
    }

    std::cout << min_total_cost << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}