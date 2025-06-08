#include <iostream> // Include the input/output stream library

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        long long distinct_values = (n * n) / 4 + 1;

        std::cout << distinct_values << "\n";
    }

    return 0;
}