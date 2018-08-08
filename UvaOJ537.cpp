#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<cstdio>

using namespace std;

inline double getp(double i, double u)
{
	return i * u;
}

inline double geti(double p, double i)
{
	return p / i;
}

inline double getu(double p, double i)
{
	return p / i;
}

inline contain(char* s, char p)
{
	for (int i = 0; i < int(sizeof(s) / sizeof(char)); ++i)
		if(p == s[i]) return i;
	return -1;
}

double atod(string s)
{
	stringstream ss(s);
	double d = 0.0;
	ss >> d;
	return d;
}

int main()
{
	int T; // number of test cases
	cin >> T;
	double val[3] = {-1, -1, -1};
	char con[] = {'P', 'U', 'I'};
	char pre[] = {'m', 'k', 'M'};
	while(T--)
	{
		string exp;
		getchar();
		getline(cin, exp);
		val[0] = val[1] = val[2] = -1;
		char p = '\0';
		int pos = -1;
		while((pos = exp.find('=', pos+1)) != -1) 
		{
			int pos1 = pos;

			while(++pos1) if(!isdigit(exp[pos1]) && exp[pos1] != '.') break;
			if(contain(pre, exp[pos1]) != -1) p = exp[pos1];

			double number = atod(exp.substr(pos+1, pos1-pos-1));
			int v = contain(con, exp[pos-1]);
			
			if(p == 'm') val[v] = 0.001 * number;
			else if(p == 'k') val[v] = 1000 * number;
			else if(p == 'M') val[v] = 1000000 * number;
			else val[v] = number;
		}
		if(val[0] == -1)
			printf("P=%.2fW\n", getp(val[1], val[2]));
		else if(val[1] == -1)
			printf("U=%.2fV\n", getu(val[0], val[2]));
		else
			printf("I=%.2fA\n", geti(val[0], val[1]));
	}

	return 0;
}