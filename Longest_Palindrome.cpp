#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    // Input size of string
    int n;
    cin >> n;
    // Input the string itself
    string s;
    cin >> s;
    
    // Initialize variables to track the longest palindrome found
    int maxLength = 1;  // Minimum palindrome length is 1 (single character)
    int start = 0;      // Starting index of the longest palindrome found
    
    // Check each position as potential center of palindrome
    for(int center = 0; center < n; center++) {
        // Handle odd length palindromes (like "aba", "abcba")
        // Start with single character and expand around center
        int left = center, right = center;
        while(left >= 0 && right < n && s[left] == s[right]) {
            int currentLength = right - left + 1;
            // Update if we found a longer palindrome
            if(currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            // Expand palindrome by moving outwards
            left--;
            right++;
        }
        
        // Handle even length palindromes (like "abba", "abbba")
        // Start with two adjacent characters and expand around center
        left = center;
        right = center + 1;
        while(left >= 0 && right < n && s[left] == s[right]) {
            int currentLength = right - left + 1;
            // Update if we found a longer palindrome
            if(currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            // Expand palindrome by moving outwards
            left--;
            right++;
        }
    }
    
    // Output the length of longest palindrome found
    cout << maxLength << endl;
    // Output the actual palindrome substring
    cout << s.substr(start, maxLength) << endl;
    
    return 0;
}