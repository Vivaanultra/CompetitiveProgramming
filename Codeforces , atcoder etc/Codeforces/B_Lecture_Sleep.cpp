#include <iostream>
#include <string>
#include <vector>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;
    int n = s.length();

    // ps[i] stores the number of pairs s[j]==s[j+1] for j < i.
    // The array is 0-indexed. Its size is n to handle queries up to r=n.
    std::vector<int> ps(n, 0); 
    for (int i = 1; i < n; i++) {
        // Start with the previous count.
        ps[i] = ps[i-1]; 
        // If the pair ending at index i (i.e., s[i-1] and s[i]) is a match, increment.
        if (s[i] == s[i-1]) {
            ps[i]++;
        }
    }

    int m;
    std::cin >> m;
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        
        // The query is for pairs s[i]==s[i+1] where i ranges from l-1 to r-2.
        // We want the sum of matches in this range.
        // Total matches up to index r-2 is stored in ps[r-1].
        // Total matches up to index l-2 is stored in ps[l-1].
        // The difference gives the count for the desired range.
        std::cout << ps[r - 1] - ps[l - 1] << "\n";
    }

    return 0;
}