/*------------------------------------------------*/
/*---implement string in three different ways-----*/
/*------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

const int LIMIT_SIZE = 10;
struct STRING{
	int limit_size = LIMIT_SIZE;
	char str[LIMIT_SIZE + 1];
};

