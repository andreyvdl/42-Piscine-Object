#include "Bank.hpp"

int main()
{
	// Account accountA = Account();
	// accountA.id = 0;
	// accountA.value = 100;
	Account accountA(0, 100);

	// Account accountB = Account();
	// accountB.id = 1;
	// accountB.value = 100;
	Account accountB(1, 100);

	Bank bank = Bank();
	// bank.liquidity = 999;
	// bank.clientAccounts.push_back(&accountA);
	// bank.clientAccounts.push_back(&accountB);
	bank.setLiquidity(999);
	bank.addAccount(&accountA);
	bank.addAccount(&accountB);

	// bank.liquidity -= 200;
	bank.setLiquidity(bank.getLiquidity() - 200);
	// accountA.value += 400;
	bank.deposit(0, 400);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
