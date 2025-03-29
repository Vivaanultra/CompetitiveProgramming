#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    vector<int> vecin((a+b));
    vector<int> vecout(b);
    int j = 0;
    while (j<b)
    {
    for (int i =0; i < (a+b); i++)
        {
            int x;
            cin >> x;
            vecin[i] = x;
            if (x == -1)
            {
                vector<int> temp_vecin = vecin;
                vector<int> temp_vecout = vecout;
                sort(temp_vecin.begin(), temp_vecin.end());
                sort(temp_vecout.begin(), temp_vecout.end());
                int k = (a+b);
                int l = temp_vecout.size();
                if(j > 0){
                while(temp_vecout[l-1] == temp_vecin[k-1])
                {
                    k-=1;
                    l-=1;
                }}
                vecout[j] = temp_vecin[k-1];
                
                j +=1;
            }

        }
    }
    for (int modi = 0; modi < vecout.size(); modi++)
        {
            cout << vecout[modi] << "\n";
        }

}