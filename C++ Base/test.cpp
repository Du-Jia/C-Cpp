#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main ()
{
//  std::string pi = "pi is " + std::to_string(3.1415926);
//  std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";
//  std::cout << pi << '\n';
//  std::cout << perfect << '\n';

    char temp[100];
    scanf("%s", temp);
    int n = atoi(temp);
    cout << n << endl;

    return 0;
}
