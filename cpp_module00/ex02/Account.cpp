#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account()
{

}

void Account::_displayTimestamp()
{
	time_t currenttime = time(0);
	tm *ltm = localtime(&currenttime);
	std::cout << 1900 + ltm->tm_year << "." << 1 + ltm->tm_mon << "."
				<< ltm->tm_mday << "	" << ltm->tm_hour << ":" 
				<< ltm->tm_min << std::endl;
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = Account::_nbAccounts;
	_nbDeposits = 0;
	Account::_nbAccounts++;
	_nbWithdrawals = 0;
	Account::_totalAmount += _amount;
	std::cout << "index:" << _accountIndex <<
	";amount:" << _amount << ";created" 
	<< "		" ;
	_displayTimestamp();
}

Account::~Account()
{
	std::cout << "index:" << _accountIndex <<
	";amount:" << _amount << ";closed" 
	<< "		";
 	_displayTimestamp();
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
	std::cout << "Accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals
				<< "		";
	_displayTimestamp();
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "index:" << _accountIndex
				<<";p_amount:" << _amount - deposit
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits 
				<< std::endl;
	_displayTimestamp();
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex
				<<";p_amount:" << _amount
				<< ";withdrawal:" << "refused;"
				<< std::endl;
		_displayTimestamp();
		return (false);
	}
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "index:" << _accountIndex
				<<";p_amount:" << _amount + withdrawal
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	_displayTimestamp();
	return (true);
}

void	Account::displayStatus( void ) const
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawal:" << _nbWithdrawals 
				<< "		";
				_displayTimestamp();

}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

