/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:28:54 by mcarton           #+#    #+#             */
/*   Updated: 2025/10/15 15:13:42 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    std::cout   << " index:" << _accountIndex
                << ";amount:" << _amount
                << ";created\n";
}

Account::~Account()
{
    _displayTimestamp();
    std::cout   << " index:" << _accountIndex
                << ";amount:" << _amount
                << ";closed\n";

    _nbAccounts--;
    _totalAmount -= _amount;
}

void Account::displayStatus(void) const 
{
   _displayTimestamp();
    std::cout   << " index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout   << " accounts:" << _nbAccounts
                << ";total:" << _totalAmount
                << ";deposits:" << _totalNbDeposits
                << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout   << " index:" << _accountIndex
                << ";p_amount:" << _amount
                << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout   << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout   << " index:" << _accountIndex
                    << ";p_amount:" << _amount
                    << ";withdrawal:refused\n";
        return (false);
    }

    _displayTimestamp();
    std::cout   << " index:" << _accountIndex
                << ";p_amount:" << _amount
                << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _totalAmount-= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout   << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm* timeinfo = std::localtime(&now);

    std::cout   << "[" << (1900 + timeinfo->tm_year)
                << std::setfill('0') << std::setw(2) << (1 + timeinfo->tm_mon)
                << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
                << "_"
                << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
                << std::setfill('0') << std::setw(2) << timeinfo->tm_min
                << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
                << "]";
}