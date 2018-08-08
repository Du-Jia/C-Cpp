#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	getchar();
	string a;
	while(n--)
	{
		getline(cin, a);
		reverse(a.begin(), a.end()) ;
		cout << a << endl;
	}
	return 0;
}