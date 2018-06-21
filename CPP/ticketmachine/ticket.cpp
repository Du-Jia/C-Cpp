#include "stdafx.h"
#include "ticket.h"


ticket::ticket()
{
}


ticket::~ticket()
{
}

int a = 0;
void ticket::showBalance()
{
	int a = 1;
	cout << ::a << ' ' << a << endl;
}

void ticket::showPrice()
{

}
void ticket::setBalance(int balance)
{
	this->balance = balance;
}

void ticket::setPrice(int price)
{
	this->price = price; 
}