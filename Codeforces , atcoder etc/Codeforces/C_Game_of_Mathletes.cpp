#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int testcases;
    cin >> testcases;
    for(int loop1 = 0; loop1 < testcases; loop1++)
    {
        int score = 0;
        int elementsofarray;
        long long int sumofab;
        cin >> elementsofarray >> sumofab;
        vector<int> vec(elementsofarray);
        for(int loop2 = 0; loop2 < elementsofarray; loop2++)
        {
            int a;
            cin >> a;
            vec[loop2] = a;
        }
        sort(vec.begin() , vec.end());
        int gameturns = elementsofarray/2;
        int sortarraybegin = 0;
        int sortarrayend = elementsofarray-1;
        for(int loop3 = 0; loop3 < elementsofarray; loop3++)
        {
            int scoredecoy = vec[sortarraybegin] + vec[sortarrayend];
            if (scoredecoy < sumofab)
            {
                ++sortarraybegin;
            }
            else if(scoredecoy > sumofab)
            {
                --sortarrayend;
            }
            else if (scoredecoy == sumofab)
            {
                score = score+1;
                ++sortarraybegin;
                --sortarrayend;
            }
            if(sortarraybegin >= sortarrayend)
            {
                break;
            }
        }
        cout << score << endl;
            
        
    }
}