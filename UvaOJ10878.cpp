#include <iostream>
#include <string>
#include <memory.h>
#include <cstdio>
#include<cstring>
using namespace std;
const int conPow[]={1,2,4,8,16,32,64,128,256,512};
char buf[100];
char toDecimal(string & str){
	char v=0;
	for (int i=str.size()-1;i>=0;--i)
	{
		v=v+(str[i]-'0')*(conPow[str.size()-i-1]);
	}
	return v;
}


int main(){
	gets(buf);
	string a = "";
	while (gets(buf)&&strcmp(buf,"___________"))
	{
		string bin="";
		int len=strlen(buf);
		for (int i=0;i<len;++i)
		{
			if(buf[i]==' ')bin+='0';
			else if(buf[i]=='o')bin+='1'; 
		}
		printf("%c",toDecimal(bin));
		a += toDecimal(bin);
	}
	cout << a << endl;
	return 0;
}
