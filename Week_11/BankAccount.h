#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include "Person.h"

class BankAccount
{
public:
	BankAccount(const Person& owner, double balance = 0.0);

	bool Withdraw(double amount);
	void Deposit(double amount);

	void SetOwner(const Person& newOwner);
	Person GetOwner() const;

	void SetBalance(double newBalance);
	double GetBalance() const;

	double OwnerProfit() const;

private:
	Person owner;
	double balance;
};

#endif
