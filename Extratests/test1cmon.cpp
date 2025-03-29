#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	//how the actual hell is this a fibonacci sequence problem???????
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll length;
	cin >> length;
	ll fib1 = 1;
	ll fib2 = 1;
	ll sum =0;
	if (length < 2)
	{
		cout << 1;
	}
	else
	{
		for(ll i = 1; i < length; i++)
		{
			sum = (fib1 + fib2);
			fib2 = fib1;
			fib1 = sum;
		}
		cout << sum;
	}
	

}
