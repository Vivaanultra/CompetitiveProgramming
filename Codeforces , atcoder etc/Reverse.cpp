#include<bits/stdc++.h>
using namespace std;


// This program reverses text both line-wise and word-wise while removing punctuation
// Input: First line contains N (number of lines), followed by N lines of text
// Output: Lines in reverse order, with words in each line also reversed
// Constraints: 1 <= N <= 10000, max 80 characters per line
int main()
{
    int lines;
    cin >> lines;                    // Read number of lines
    cin.ignore();                    // Clear input buffer
    vector<string> v;                // Vector to store input lines
    for (int i = 0; i < lines; i++)
    {
        string s;
        getline(cin, s);            // Read each line
        v.push_back(s);             // Store in vector
    }
    reverse(v.begin(), v.end());    // Reverse the order of lines
    for(string i : v)               // Process each line
    {
        string temp;
        for(char j : i)             // Remove punctuation, keep only letters and spaces
        {
            if (isalpha(j) || j == ' ')  // isalpha() checks if character is a letter (A-Z or a-z)
            {
                temp += j;
            }
        }
        stringstream ss(temp);      // Create stringstream to split into words
        vector<string> words;       // Vector to store words
        string word;
        while(ss >> word) {         // Extract words from the line
            words.push_back(word);
        }
        reverse(words.begin(), words.end());    // Reverse order of words
        for(int k = 0; k < words.size(); k++) { // Print words with spaces
            cout << words[k];
            if(k < words.size() - 1) cout << " ";
        }
        cout << endl;               // New line after each line of output
    }
}