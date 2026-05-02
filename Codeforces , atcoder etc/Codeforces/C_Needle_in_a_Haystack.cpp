#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;

        // 1. Count frequencies in t
        vector<int> count(26, 0);
        for (char c : t) count[c - 'a']++;

        // 2. Remove characters required for s
        bool possible = true;
        for (char c : s)
        {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) possible = false;
        }

        if (!possible)
        {
            cout << "Impossible\n";
            continue;
        }

        // 3. Separate remaining characters into Left (< s[0]), Mid (== s[0]), Right (> s[0])
        string left = "", mid = "", right = "";
        char start_char = s[0];

        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            string chunk(count[i], c); // Create string of 'count' copies of 'c'

            if (c < start_char) left += chunk;
            else if (c == start_char) mid += chunk;
            else right += chunk;
        }

        // 4. Decide if s goes before or after the 'mid' block
        // Scan s for the first character different from s[0]
        bool s_goes_first = false;
        for (size_t i = 1; i < s.size(); i++)
        {
            if (s[i] < start_char)
            {
                s_goes_first = true;
                break;
            }
            if (s[i] > start_char)
            {
                s_goes_first = false;
                break;
            }
        }

        // 5. Assemble and print
        cout << left;
        if (s_goes_first) cout << s << mid;
        else cout << mid << s;
        cout << right << "\n";
    }
    return 0;
}