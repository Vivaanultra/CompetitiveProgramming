#include <iostream>
#include <vector>
#include <cmath> // For sqrt and round

// Maximum value of the square root of x_i. If x_i <= 10^12, then sqrt(x_i) <= 10^6.
const int MAX_ROOT_VAL = 1000000; 
std::vector<bool> is_prime_sieve_data(MAX_ROOT_VAL + 1);

void precompute_primes_sieve() {
    // Initialize all numbers as prime
    for (int i = 0; i <= MAX_ROOT_VAL; ++i) {
        is_prime_sieve_data[i] = true;
    }
    is_prime_sieve_data[0] = false; // 0 is not prime
    is_prime_sieve_data[1] = false; // 1 is not prime

    // Sieve of Eratosthenes
    // Iterate up to sqrt(MAX_ROOT_VAL). sqrt(10^6) = 1000.
    for (long long p = 2; p * p <= MAX_ROOT_VAL; ++p) {
        if (is_prime_sieve_data[p]) {
            // Mark all multiples of p (starting from p*p) as not prime
            for (long long i = p * p; i <= MAX_ROOT_VAL; i += p) {
                is_prime_sieve_data[i] = false;
            }
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute_primes_sieve();

    int n;
    std::cin >> n;

    for (int k = 0; k < n; ++k) {
        long long x_val;
        std::cin >> x_val;
        
        // Calculate the integer closest to sqrt(x_val)
        // Cast x_val to double for sqrt function
        long long root_candidate = static_cast<long long>(round(sqrt(static_cast<double>(x_val))));
        
        bool is_t_prime = false;
        
        // Check if root_candidate is positive (will be if x_val >= 1)
        // and if its square is indeed x_val.
        // Since x_val >= 1, root_candidate will be >= 1.
        if (root_candidate * root_candidate == x_val) {
            // x_val is a perfect square of root_candidate.
            // root_candidate will be at most MAX_ROOT_VAL (10^6) because x_val <= 10^12.
            // So, access to is_prime_sieve_data[root_candidate] is safe.
            if (is_prime_sieve_data[root_candidate]) {
                is_t_prime = true;
            }
        }
        
        if (is_t_prime) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}