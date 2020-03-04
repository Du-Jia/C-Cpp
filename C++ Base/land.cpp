#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main()
{
	int n = 0;
	while(cin >> n)
	{
		int v =0 , e = 0, f = 0;
		for (int i = 0; i < n-1; ++i)
		{
			v += i * (n - 2 - i);
		}
		v = (v * n /4 + n);

		for (int i = 0; i < n-1; ++i)
		{
			e += i * (n - 2 - i) + 1;
		}
		e = e * n /2 + n;

		f = e - v + 1;
		cout << f << endl;
	}
	return 0;
}