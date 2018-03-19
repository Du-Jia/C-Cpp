#include<stdio.h>
#include<stdlib.h>

enum {OVERFLOW = -2, ERROR, FALSE, TRUE};

//define polynomial
typedef struct Node *PtrToNode;
typedef struct Node Node;
typedef struct Node{
	 int Coefficient;
	 int Exponent;
	 struct Node *next;
}*Polynomial;

//implement basic funcion
Polynomial CreatePoly(int num);

Polynomial Add(Polynomial p1,Polynomial p2);

Polynomial Multiple(Polynomial p1, Polynomial p2);

void DestroyPoly(Polynomial* p);

void printPoly(Polynomial polynomial);
