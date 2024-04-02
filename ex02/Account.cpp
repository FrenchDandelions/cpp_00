#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(){
    time_t now = time(0);
    struct tm *timestamp = localtime(&now);
    char buf[80];
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", timestamp);
    std::cout << buf << std::flush;
    return;
}

Account::Account(int deposit) : _accountIndex(_nbAccounts), _amount(deposit), _nbDeposits(0), _nbWithdrawals(0){
    _displayTimestamp();
    std::cout << "index:" << _nbAccounts << ";" << "amount:" << deposit << ";created" <<std::endl;
    _totalAmount += _amount;
    _nbAccounts++;
}

Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";closed" <<std::endl;
    return;
}

int Account::getNbAccounts(void){
    return(_nbAccounts);
}

int Account::getTotalAmount(void){
    return(_totalAmount);
}

int Account::getNbDeposits(void){
    return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void){
    return(_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit){
    int next_amount = deposit + _amount;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << next_amount << ";nb_deposits:" << _nbDeposits << std::endl;
    _totalAmount += deposit;
    _amount += deposit;
}

int Account::checkAmount(void) const {
    return(_amount);
}

void Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
    if(withdrawal > checkAmount()){
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return(false);
    }
    else{
        int next_amount = _amount - withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << next_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        return(true);
    }
}
