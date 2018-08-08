#include<cstdio>
#include<string>
#include<cctype>
#include<set>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;



int main()
{
	char ch, pre;
	pre = '\0';
	string word;
	set<string> dictionary;
	bool end = false, begin = true;

	while((ch = getchar()) != EOF)
	{
		if(isalpha(pre) && isalpha(ch))
		{
			begin = true;
			end = false;
		}
		else if(!isalpha(pre) && isalpha(ch))
		{
			begin = true;
			end = false;
		}
		else if(isalpha(pre) && !isalpha(ch))
		{
			begin = true;
			end = true;
		}
		else
		{
			end = false;
			begin = false;
		}

		if(begin && !end)
			word += tolower(ch);
		if(begin && end)
		{
			dictionary.insert(word);
			word = "";
		}
		pre = ch;
	}

	for(set<string>::iterator it = dictionary.begin();
		it != dictionary.end();++it)
	{
		cout << *it << endl;
	}
	return 0;
}
