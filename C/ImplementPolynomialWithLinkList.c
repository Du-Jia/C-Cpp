#include "ImplementPolynomialWithLinkList.h"

int
main(){
	//test function
	printf("Please input the first polynomial\n");
	Polynomial poly1 = CreatePoly(4);
	printf("Please input the second\n");
	Polynomial poly2 = CreatePoly(5);
	printPoly(poly1);
	printPoly(poly2);
	printf("Add poly1 ploy2: \n");
	printPoly(Add(poly1, poly2));
	return 0;
}

/*
*You can create a polynomial which has 
*num items and use it as you argument
*/
Polynomial 
CreatePoly(int num){
	Polynomial poly = (PtrToNode)malloc(sizeof(Node));
	if(!poly) exit(OVERFLOW);
	int i = 0;
	int Coefficient[] = {1,2,3,4};
	int Exponent[] = {2,3,4,5};

	Polynomial tail = poly;
	//initial poly
	for(i = 0; i < num; i++){
		PtrToNode new = (PtrToNode)malloc(sizeof(Node));
		tail->next = new;
		 scanf("%d", &new->Coefficient);
		 scanf("%d", &new->Exponent);
		//init test code:
//		new->Coefficient = Coefficient[i];
//		new->Exponent = Exponent[i];
		new->next = NULL;
		tail = new;
	}
	
	return poly;
}

void
printPoly(Polynomial p){
	printf("The polynomial is: \n");
	Polynomial tmp = p->next;
	while(tmp){
		if(tmp->next != NULL){		
			printf("%dx^%d + ", tmp->Coefficient, tmp->Exponent);
		}
		else{		
			printf("%dx^%d\n", tmp->Coefficient, tmp->Exponent);
		}
		tmp = tmp->next;
	}
}

Polynomial Add(Polynomial p1, Polynomial p2){
	Polynomial res = (PtrToNode)malloc(sizeof(Node));
	Polynomial tmp1 = p1 = p1->next;
	Polynomial tmp2 = p2 = p2->next;
	Polynomial tail = res;

	while(p1 || p2){
		if(p1 && p2){
			if(p1->Exponent < p2->Exponent){
				tail->next = p1;
				tail = p1;
				p1 = p1->next;
			}
			else if(p2->Exponent > p2->Exponent){
				tail->next = p2;
				tail = p2;
				p2 = p2->next;
			}
			else{
				Polynomial new = (PtrToNode)malloc(sizeof(Node));
				new->Coefficient = p1->Coefficient + p2->Coefficient;
				new->Exponent = p1->Exponent;
				tail->next = new;
				tail = new;
				new->next = NULL;
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		else if(!p1 && p2){
			tail->next = p2;
			tail = p2;
			p2 = p2->next;
		}
		else{
			tail->next = p1;
			tail = p1;
			p1 = p1->next;
		}
	}
	return res;
}

/*思路描述：
* 乘法产生的结果最多有N * M 个
* 如果直接将每一项的系数乘，最后再合并到一起，需要 
*/
Polynomial Multiple(Polynomial p1, Polynomial p2){
	
}


