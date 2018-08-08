#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

const int num_base = 26;

int REV[] = {0, -1, -1, -1, '3'-'0'+26,
-1, -1, 'H'-'A', 'I'-'A','L'-'A',-1,
'J'-'A','M'-'A',-1,'o'-'a',-1,-1,-1,
26+'2'-'0','t'-'a','u'-'a','v'-'a','w'-'a',
'x'-'a','y'-'a',26+'5'-'0','o'-'a','1'-'0'+26,
's'-'a','e'-'a',-1,'z'-'a',-1,-1,'8'-'0',
-1};


bool isPalindromes(string str);
bool isMirrored(string str);

int main()
{
	string str;
	while(cin >> str)
	{
		int s = 0, m = 0, all = 0;
		if(isPalindromes(str)) s = 1;
		if(isMirrored(str)) m = 2;
		all = s | m;

		if(all == 0)
			cout << str << " -- is not a palindromes." << endl;
		else if(all == 1)
			cout << str << " -- is a regular palindromes." << endl;
		else if(all == 2)
			cout << str << " -- is a mirrored string." << endl;
		else if(all == 3)
			cout << str << " -- is a mirrored palindromes." << endl;
		else
			cout << "Error: all = " << all<< endl;
	}
	return 0;
}

bool isPalindromes(string str)
{
	int len = str.size();
	bool flag_p = true;
	for (int i = 0; i < len / 2; ++i)
	{
		if(str[i] != str[len-i-1]) flag_p = false;
	}
	return flag_p;
}

bool isMirrored(string str)
{
	int len = str.size();
	bool flag_m = true;
	for (int i = 0; i < len / 2; ++i)
	{
		int pos = isdigit(str[i])? num_base+str[i]-'0' : str[i] - 'A';
		int rev = isdigit(str[len-i-1])?num_base+str[len-i-1]-'0': str[len-i-1]-'A';
		if(REV[pos] != rev) return false;
	}
	return flag_m;
}