#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int words;
    while (cin >> words && words != 0)
    {
        int maxscore = -1;  // Initialize to -1 to handle case of no double vowels
        string bestword;
        for (int j = 0; j < words; j++)
        {
            string word;
            cin >> word;
            int score = 0;
            for (int k = 0; k < word.length() - 1; k++)
            {
                if (word[k] == 'a' && word[k + 1] == 'a') score++;
                else if (word[k] == 'e' && word[k + 1] == 'e') score++;
                else if (word[k] == 'i' && word[k + 1] == 'i') score++;
                else if (word[k] == 'o' && word[k + 1] == 'o') score++;
                else if (word[k] == 'u' && word[k + 1] == 'u') score++;
                else if (word[k] == 'y' && word[k + 1] == 'y') score++;
            }
            if (score >= maxscore)  // Changed to >= to handle first word case
            {
                maxscore = score;
                bestword = word;
            }
        }
        cout << bestword << "\n";  // Changed endl to \n for better performance
    }
}