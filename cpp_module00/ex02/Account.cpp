#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account()
{

}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = Account::_nbAccounts;
	_nbDeposits = 0;
	Account::_nbAccounts++;
	_nbWithdrawals = 0;
	Account::_totalAmount += _amount;
	std::cout << "an Account created with index - " << _accountIndex <<
	"and amount - " << _amount << std::endl;
}

Account::~Account()
{
	std::cout << "emty account created" << std::endl;
}

void Account::_displayTimestamp()
{
	
}


int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	std::cout << "nb Accounts - " << Account::_nbAccounts
				<< "total amount - " << Account::_totalAmount
				<< "total number of deposits" << Account::_totalNbDeposits
				<< "total num of withdrawals" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_nbDeposits++;
	std;;cout << "made a deposit" << std::endl
				<< "amount of this deposit - " << deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
	{
		std::cout << "not enough deposit" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "made a withdrawal" << std::endl
				<< "amount of withdrawal - " << withdrawal << std::endl;
	return (true);
}

void	Account::displayStatus( void ) const
{
	std::cout << "amount - " << _amount
				<< "total amount" << Account::_totalAmount << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

