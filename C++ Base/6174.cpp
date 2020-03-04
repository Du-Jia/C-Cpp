#include<iostream>
#include<cstring>

using namespace std;

void sort(char* num, int n, bool flag)
{
	int i = 0, j = 0;
	if(flag)
		for(; i < n; i++)
		{
			for(j = i+1; j < n; j++)
			{
				if(num[i] > num[j])
				{
					int temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				}
			}
		}
	else
		for(; i < n; i++)
		{
			for(j = i+1; j < n; j++)
			{
				if(num[i] < num[j])
				{
					int temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				}
			}
		}
}

int atoi(char * num, int n)
{
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		c *= 10;
		c += (num[i] - '0');
	}

	return c;
}

void itoa(int num, int  n, char *c)
{
	int  i = n;
	while(num > 0)
	{
		c[--i] = num % 10 + '0';
		num /= 10;
	}
}

int main()
{
	int n = 0;
	char* num = new char[n];

	cin >> n;
	// n = 3;

	int number = 0;
	cin >> number;

	// number = 312;

	itoa(number, n, num);
	sort(num, n, true);
	int b = atoi(num);
	sort(num, n, false);
	int a = atoi(num);
	while(true)
	{
		cout << number << " -> ";
		number = a - b;
		itoa(number, n, num);
		sort(num, n, false);
		a = atoi(num, n);
		sort(num, n, true);
		b = atoi(num, n);
		if(number == (a - b)){
			cout << number << " ->";
			break;
		}
	}
	cout << number << endl;

	return 0;
}
