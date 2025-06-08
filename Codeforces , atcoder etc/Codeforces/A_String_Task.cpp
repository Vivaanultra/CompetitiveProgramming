#include <iostream>
#include <string>
#include <cctype> // For tolower()

// Function to check if a character is a vowel
bool is_vowel(char c) {
    // Convert to lowercase for consistent checking
    c = tolower(c);
    return (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i');
}

int main() {
    // Use std namespace for convenience in competitive programming
    using namespace std;

    // Optimize C++ standard streams for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input_string;
    cin >> input_string; // Read the input string

    string result_string = ""; // Initialize an empty string to store the result

    // Iterate through each character of the input string
    for (char ch : input_string) {
        // Convert the character to lowercase
        char lower_ch = tolower(ch);

        // If the character is not a vowel (it's a consonant)
        if (!is_vowel(lower_ch)) {
            result_string += '.';       // Insert a '.' before the consonant
            result_string += lower_ch;  // Append the lowercase consonant
        }
    }

    cout << result_string << endl; // Print the resulting string

    return 0;
}