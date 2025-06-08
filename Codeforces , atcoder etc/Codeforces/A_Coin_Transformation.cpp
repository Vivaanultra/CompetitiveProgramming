#include <iostream>
#include <map>

std::map<long long, long long> memo_global;

long long calculate_max_coins(long long n) {
    if (n <= 3) {
        return 1;
    }

    if (memo_global.count(n)) {
        return memo_global[n];
    }

    long long value_of_new_coins = n / 4;

    long long result = calculate_max_coins(value_of_new_coins) + calculate_max_coins(value_of_new_coins);
    
    memo_global[n] = result;
    
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        long long n_input;
        std::cin >> n_input;
        
        memo_global.clear(); 
        
        std::cout << calculate_max_coins(n_input) << std::endl;
    }

    return 0;
}