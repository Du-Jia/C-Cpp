#include <stdio.h>
#define MAXSTRLEN 255

typedef int Status;
typedef unsigned char SString[MAXSTRLEN + 1];
enum {OVERFLOW=-2, ERROR, FALSE, TRUE};

//declare all the functions
Status CreateString(SString s);
Status Copy(SString s, SString rs);
Status Concat(SString s1, SString s2, SString s);
void PrintStr(SString s);
Status SubString(SString sub, SString par, int pos, int len);
