#include "List.h"

//main fuction to test all the fuction in this file
//int main(){
/*第三章3.2*/
//	int i = 0;
//	List L1, L2;	
//	L1 = CreateList(10);
//	printf("Create List :\n");
//	printN(L1);
//	L2 = CreateList(5);
//	printf("Create List: \n");
//	printN(L2);
//	printLots(L1, L2);

/*----------------测试函数---------基本功能实现----------------*/
//	List L = (List)malloc(sizeof(Node));
//	L->next = NULL;
//	
//	printf("Is The List Empty?\n%s\n", IsEmpty(L)? "yes":"not");

//	L = CreateList(0);
//	//test the IsEmpty function
//	printf("Is The List Empty?\n%s\n", IsEmpty(L)? "yes":"not");
	//test CreateList and printN

	//Test IsLast function
//	Position P = L->next;
//	printf("The node is the tail of the List L?\n%s\n", IsLast(P, L)? "yes":"not");
//	while( !IsLast(P, L) ) {
//		P = P->next ;
//		printf("%isuccessful\n", i++);
//	}
//	printf("The node is the tail of the List L?\n%s\n", IsLast(P, L)? "yes":"not");	
	
	//test MakeEmpty
//	DeleteList(L);
////	printN(L);
//	printf("Is the List L empty?\n%s\n", IsEmpty(L)? "yes" : "not");
	
	//test Find
//	printf("Find 3 and print:\n%i\n", Find(3, L)->data);
	//test FindPrevious
//	printf("Find 3 and print:\n%i\n", FindPrevious(3, L)->data);
//	
//	//test Insert 
//	printf("Insert a number after 3: %d\n ", 111);
//	Insert(111, L, Find(3, L));
//	printN(L);
//	
//	//test Delete
//	printf("Delete 111 from L: \n");
//	Delete(111, L);
//	printN(L);
//	return 0;
//}

//If the position is the tail of the List return 1
//we needn't List L now, but we may need it later.
int 
IsLast(Position P, List L){
	return P->next == NULL;
}

//create a new list and return the list
List CreateList(int m){
	int i = 0;
	
	List L = (PtrToNode)malloc(sizeof(Node));
	if( L == NULL ) return 0;
	
	Position P = NULL;
	
	/* 使用头插法创建线性表*/
//	L->next = NULL;
//	for(; i < m; i++){
//		PtrToNode p = (PtrToNode)malloc(sizeof(Node));
//		if(p == NULL)return 0;
//		
////		while( IsLast(P = P->next, L)){			
//	//		test code
//			p->data = i;
//			p->next = L->next;
//			L->next = p;
////		}
//	}
	/*尾接法创建链表*/
	/*基本思路：
	* 将新建的节点作为新的尾节点接到之前的尾节点上 
	*/ 
	L->next = NULL;
	Position tail = L->next;
	printf("Please input your data:\n");
	for(; i < m; i++){
		Node* newN = (PtrToNode)malloc(sizeof(Node));
		
//		scanf("%d", &newN->data);
		newN->data = i + 1;
		if(L->next == NULL){
			tail = newN;
			L->next = tail;
		}
		else{
			tail->next = newN;
			tail = newN;
		}
		
		newN->next = NULL;
	} 
	return L;
}

//print all number in the list
int 
printN(List L){
	PtrToNode p = L;
	if(p->next == NULL ) return 0;
	
	while( (p = p->next) ){
		printf("\t%i\n", p->data);
	}
	return 1;
}

//return 0 while the List is null, or return 1 while the List has something 
int 
IsEmpty( List L ){
	return L->next == NULL;
}

//Make the List Empty
void 
DeleteList(List L){
	if( L->next != NULL ){
		PtrToNode tmp, p = L->next;

//		printf("free\n");  //test code
		
		while( p != NULL ){
			tmp = p->next;
//			printf("%d\n", p->data);
			printf("free\n");
			free(p);
			p = tmp;
		}
	}
	
	L->next = NULL;
//	printf("Is the List L empty?\n%s\n", IsEmpty(L)? "yes" : "not");
}

Position 
Find(ElemType x, List L){
	Position p = L->next;
	
	if(IsEmpty(L)) return ERROR;
	
	while( p->next != NULL && x != p->data ){
		p = p->next;
	}
	
	return p;
}

Position
FindPrevious(ElemType x, List L){
	Position p = L->next;
	
	if(IsEmpty(L)) return ERROR;
	
	while( p != NULL && x != p->next->data ){
		p = p->next;
	}
	
	return p;
}

/* Insert a node which value is x after P in L */
void
Insert(ElemType x, List L, Position P){
	Position tmp = (PtrToNode)malloc(sizeof(Node));
	if( tmp == NULL ) 
		printf("Malloc error : Overflow\n");
		
	tmp->data = x;
	tmp->next = P->next;
	P->next = tmp;
}

void
Delete(ElemType x, List L){
	Position p, tmp ;
	
	p = FindPrevious(x, L);
	
	if( !IsLast(p, L)){
		tmp = p->next;
		p->next = tmp->next;
		free(tmp);	
	}
}

void
printLots(List l1, List l2){
	PtrToNode p = l1->next;
	PtrToNode q = l2->next;
	int end = 0;
	int i = 0;
	for(i = 1; q; q = q->next){
		for(end = q->data; i < end; i++, p = p->next);
		printf("In l2, position is : %d\n, print it in l1: %d\n", q->data, p->data);
	}
}

/*第三章3.3
*仅通过交换指针来交换两个相邻的元素 
*/ 
