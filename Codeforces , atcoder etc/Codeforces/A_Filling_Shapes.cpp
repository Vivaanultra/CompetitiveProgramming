#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    if(n % 2 == 0) cout << (1LL << (n/2)) << endl;
    else cout << 0 << endl;

    // The expression (1LL << (n/2)) uses the left shift operator (<<)
    // 1LL is a 64-bit integer literal equal to 1
    // Shifting left by k positions is equivalent to multiplying by 2^k
    // So 1LL << (n/2) calculates 2^(n/2)
}