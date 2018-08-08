#include<iostream>

using namespace std;

int main()
{
	int n;
	int k = 1, s = 0;
	while(cin >> n)
	{
		s = 0, k = 1;
		for(;;)
		{
			s += k;
			if(s >= n)
			{
				cout << s-n+1 << '/' << k-s+n << endl;
				break;
			}
			k++;
		}
	}
	return 0;
}