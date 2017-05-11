#include "BankAccount.h"

BankAccount::BankAccount(const Person& owner, double balance)
{
	SetOwner(owner);
	SetBalance(balance);
}

void BankAccount::SetOwner(const Person& newOwner)
{
	owner = newOwner;
}

Person BankAccount::GetOwner() const
{
	return owner;
}

void BankAccount::SetBalance(double newBalance)
{
	balance = newBalance;
}

double BankAccount::GetBalance() const
{
	return balance;
}

bool BankAccount::Withdraw(double amount)
{
	if (amount > balance)
		return false;

	balance -= amount;
	return true;
}

void BankAccount::Deposit(double amount)
{
	balance += amount;
}

double BankAccount::OwnerProfit() const
{
	return 0.0;
}
