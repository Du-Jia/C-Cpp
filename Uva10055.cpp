#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	long long a, b;
	while((scanf("%lld%lld", &a, &b)) != EOF)
	{
		printf("%lld", a > b? a-b : b - a);
	}
	return 0;
}