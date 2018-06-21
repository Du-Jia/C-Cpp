#pragma once
class ticket
{
public:
	ticket();
	~ticket();
	void showBalance();
	void showPrice();
	void setBalance(int);
	void setPrice(int );
private:
	int balance;
	int price;
};

