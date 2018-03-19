#include "SString.h"

int
main(){
    int i = 0;
    SString s1, s2, s;
    CreateString(s1);
    CreateString(s2);
    Concat(s1, s2, s);
    printf(s);
//    SString sub;
//    SubString(sub, s, 5, 10);
//    PrintStr(sub);
    return 0;
}

void
PrintStr(SString s){
    int i = 1, len = s[0];

    for(; i <= len; i++){
    	printf("%c\n", s[i]);
        printf("%c", s[i]);
    }
    putchar('\n');
}

Status
CreateString(SString s){
    char c;
    int i = 0;
    while( (c = getchar()) != '\n'){
        s[++i] = c;
    }
    s[0] = i;
    return TRUE;
}

Status
Copy(SString s, SString rs){
    rs[0] = s[0];

    int i = 0;
    while(++i <= s[0]){
        rs[i] = s[i];
    }
    return TRUE;
}

Status
Concat(SString s1, SString s2, SString s){
    Copy(s1, s);
    int len1 = s1[0], len2 = s2[0];
    int i = len1 + 1;
    if(len1 + len2 <= MAXSTRLEN){
    	s[0] = len1 + len2;
        for(; i <= len1 + len2; i++){
//        	//test
//        	putchar(s2[i - len2]);
            s[i] = s2[i - len1];
        }
    }
    else{
    	s[0] = MAXSTRLEN;
        for(; i <= MAXSTRLEN; i++){
            s[i] = s2[i - len1];
        }
    }

    return TRUE;
}

Status
SubString(SString sub, SString par, int pos, int len){
    if(len + pos > par[0] || pos < 0 || len < 0)
        return ERROR;
    else{
        sub[0] = len;
        int i = 1;
        for(; i <= len; i++){
            sub[i] = par[i + pos - 1];
        }
        return TRUE;
    }
}
