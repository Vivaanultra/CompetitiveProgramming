#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int off1, off2 , off3;
    cin >> off1 >> off2 >> off3;
    vector<int> combined(off1+off2+off3);
    vector<int> output;
    for (int i = 0; i < off1+off2+off3; i++)
    {
        int x;
        cin >> x;
        combined[i] = x;
    }
    sort(combined.begin(),combined.end());
    for(int i = 0; i < off1 + off2 + off3 -1; i++)
    {
        if(combined[i]==combined[i+1])
        {
            output.push_back(combined[i+1]);
        }
    }
    for(int i =0; i< output.size() -1; i++)
    {
        if(output[i]==output[i+1])
        {
            output.erase(output.begin() + i);
        }
    }
    cout << output.size() << "\n";
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << "\n";
    }
    

}