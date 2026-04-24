/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:33:55 by martinmust        #+#    #+#             */
/*   Updated: 2026/04/24 17:29:25 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <sys/time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ';';
    std::cout << "total:" << _totalAmount << ';';
    std::cout << "deposits:" << _totalNbDeposits << ';';
    std::cout << "withdrawals:" << _totalNbWithdrawals << '\n';
}

Account::Account( int initial_deposit )
{   
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "created\n";
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "closed\n";
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "p_amount:" << _amount << ';';
    std::cout << "deposit:" << deposit << ';';
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << _amount << ';';
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "p_amount:" << _amount << ';';

    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << '\n';
        return (false);
    }
    std::cout << "withdrawal:" << withdrawal << ';';
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << "amount:" << _amount << ';';
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "nb_withdrawals:" << _nbWithdrawals << '\n';
    return (true);
}

int		Account::checkAmount( void ) const
{
    return(_amount);
}

void	Account::displayStatus( void ) const
{
    // [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}

void Account::_displayTimestamp(void)
{
    struct tm *date;
    time_t now;
    time(&now);
    date = localtime(&now);
    std::cout << '[';
    std::cout << 1900 + date->tm_year;
    if (date->tm_mon + 1 < 10)
        std::cout << '0' << date->tm_mon + 1;
    else
        std::cout << date->tm_mon + 1;

    if (date->tm_mday < 10)
        std::cout << '0' << date->tm_mday << '_';
    else
        std::cout << date->tm_mday << '_';

    if (date->tm_hour < 10)
        std::cout << '0' << date->tm_hour;
    else
        std::cout << date->tm_hour;

    if (date->tm_min < 10)
        std::cout << '0' << date->tm_min;
    else
        std::cout << date->tm_min;

    if (date->tm_sec < 10)
        std::cout << '0' << date->tm_sec;
    else
        std::cout << date->tm_sec;
    std::cout << ']';
}