#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define TRUE 1
#define OVERFLOW -1

typedef int ElemType;
struct Node;
typedef struct Node Node;
typedef Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//Create a empty List
List MakeEmpty( List L);

//If the list is empty return 1
int IsEmpty(List L);

//If the node is the tail return 1
int IsLast( Position P, List L);

//Find the Position of x
Position Find( ElemType x, List L);

//Delete x from L
void Delete( ElemType x, List L);

//Find the previous element of x in L
Position FindPrevious( ElemType x, List L );

//Insert a element to L
void Insert( ElemType x, List L, Position P);

//Delete all nodes in L
void DeleteList(List L);

//return the position of the heaser node in L
Position Header(List L);

//
Position First( List L );

//
Position Advance( Position P);

//
ElemType Retrieve( Position P);

//create a list whose size is m
List CreateList(int m);

//print all the element in L
int printN(List L);

//print element in l
void printLots(List l1, List l2);

struct Node{
	int data;
	Node* next;
};
