#include "List_array.h"

int main(){
	List* L = CreateList(9);
	printN(L);
	MakeEmpty(L);
	printN(L);
//	printf("%d", L.base[2]);
	return 0;
}

//Create a loop List with m elements and return the list
List* CreateList(int m){
	List *L;
	
	L = (List*)malloc(sizeof(List));
	L->base = (Status*)malloc(sizeof(Status) * m);
	
	//if malloc filled, exit with error
	if(L->base == NULL){
	    printf("ERROR!\n");
	    exit(ERROR);
	} 
	
	//initial L
	L->length = 0;
	L->limit_size = LIMITSIZE;
	
	//make a copy of L.base to P
	Status *P = L->base; 
	
	//input all the elements 
	//test with i
	int i = 1;
	for(P++; P - L->base <= m; P++, i++){
		*P = i;
//		scanf("%d", P);
		L->length++;
	}
	
	return L; 
}

//print all the element in L
void printN(List *L){
	if(L->length == 0) exit(ERROR);
	Status *P = L->base;
	
	for(P++; P - L->base <= L->length; P++){
		printf("%d ", *P);
	}
}

void MakeEmpty(List* L){
	if(!L) exit(ERROR);
	else{
		free(L->base);
		L->base = NULL;
		L->length = 0;
	}
}

void DestroyList(List* L){
	if(!L) exit(ERROR);
	else{
		free(L->base);
		free(L);
	}
}

//position Find(Status elem, List L);
////Insert before i
//void Inser(position i, List L);
//void Delete(position i, List L);
