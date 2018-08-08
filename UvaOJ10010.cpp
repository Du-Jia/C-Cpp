#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int T, m, n;

bool ok(int i, int j)
{
	return i < m && i >=0 && j < n && j >= 0;
}


int find(char** table, string w, int &x, int& y)
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
		{	
			
			// cout << i << endl;
			int find[8];
			memset(find, 0, sizeof(find));
			for(int k = 0; k < w.size(); k++)
			{
				// //right
				// cout << "k:" << k << endl;
				if(ok(i,j+k) && w[k] == table[i][j+k])
				{
					find[6] += 1;
				}
				if(ok(i,j-k) && w[k] == table[i][j-k])
				{
					find[7] += 1;
				}
				if(ok(i-k,j-k) && w[k] == table[i-k][j-k])
				{
					find[0] += 1;
				}
				if(ok(i+k,j+k) && w[k] == table[i+k][j+k])
				{
					find[1] += 1;
				}
				if(ok(i+k,j-k) && w[k] == table[i+k][j-k])
				{
					find[2] += 1;
				}
				if(ok(i-k,j+k) && w[k] == table[i-k][j+k])
				{
					find[3] += 1;
				}
				if(ok(i-k,j) && w[k] == table[i-k][j])
				{
					find[4] += 1;
				}
				if(ok(i+k,j) && w[k] == table[i+k][j])
				{
					find[5] += 1;
				}
			}
			x = -1, y = -1;
			for(int p = 0; p < 8;p++)
			{
				// cout << "find " << p << " " << find[p] << endl;
				if(find[p] == w.size())
				{
					x = i;
					y = j;
					return 1;
				}
			}
		}
	return -1;
}

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> m >> n;
		int k;
		char ** table = new char*[m];

		for(int i =0 ; i < m; i++)
		{
			table[i] = new char[n];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> table[i];
			table[i] = strlwr(table[i]);
			// cout << table[i] << endl;
		}

		cin >> k;
		string word;
		while(k--)
		{
			cin >> word;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			int x, y;
			find(table, word, x, y);
			cout << x+1 << " " << y+1 << endl;
		}
	}
	return 0;
}