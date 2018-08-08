#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	double balance = 0;
	double sum = 0;
	int cnt = 12;
	while(cnt--)
	{
		scanf("%lf", &balance);
		sum += balance;
	}

	printf("$%.2f\n", sum / 12);
	return 0;
}