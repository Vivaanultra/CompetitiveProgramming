#include <bits/stdc++.h>
using namespace std;

int solve(int y , vector<bool> line , vector<bool> diag1 , vector<bool> diag2, vector<string> v)
{
    if(y == 8)
    {
        return 1;
    }
    int count = 0;
    for(int x = 0; x < 8; x++)
    {
        if(!line[x] && !diag1[x+y] && !diag2[x-y+7] && (v[y][x] == '.'))
        {
            line[x] = true;
            diag1[x+y] = true;
            diag2[x-y+7] = true;
            count += solve(y+1,line,diag1,diag2,v);
            line[x] = false;
            diag1[x+y] = false;
            diag2[x-y+7] = false;
        }
    }
    return count;

}

int main()
{
    vector<string> v(8);
    for(int i = 0; i < 8; i++)
    {
        cin >> v[i];
    }
    vector<bool> line(8,false);
    vector<bool> diag1(15,false);
    vector<bool> diag2(15,false);
    cout << solve(0,line,diag1,diag2,v);
    return 0;

}