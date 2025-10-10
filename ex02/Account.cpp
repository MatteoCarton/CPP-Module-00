#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

Account::Account(int initial_deposit)
{
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;

    _nbAccounts--;
    _totalAmount -= _amount;
}

void Account::displayStatus(void) const 
{
   _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << ";amount:" << _amount;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex;
        std::cout << ";p_amount:" << _amount;
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }

    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _totalAmount-= withdrawal;
    std::cout << ";amount:" << _amount;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm* timeinfo = std::localtime(&now);

    std::cout << "[" << (1900 + timeinfo->tm_year);
    std::cout << std::setfill('0') << std::setw(2) << (1 + timeinfo->tm_mon);
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_sec;
    std::cout << "]";
}