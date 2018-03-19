#include <stdio.h>
#include <stdlib.h>
 
enum {OVERFLOW = -2, ERROR, FALSE, TRUE};
const int LIMITSIZE = 10;

struct List;
typedef struct List List;
typedef int Status;
typedef int position;

 

struct List{
	int length;
	int limit_size;
	Status *base;
};

//function
List* CreateList(int);
void MakeEmpty(List *L);
void DestroyList(List *L);
position Find(Status elem, List L);
//Insert before i
void Inser(position i, List L);
void Delete(position i, List L);
void printN(List *L);

