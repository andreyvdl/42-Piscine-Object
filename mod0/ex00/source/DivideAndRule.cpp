#include "../include/Bank.hpp"
#include <iostream>

int main()
{
	Bank bank = Bank();

	bank.addClient(100);
	bank.addClient(100);
	bank.depositTo(400, 0);

	Account* accountA = bank.getAccount(0);
	Account* accountB = bank.getAccount(1);

	std::cout << "Account : " << std::endl;
	std::cout << *accountA << std::endl;
	std::cout << *accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
