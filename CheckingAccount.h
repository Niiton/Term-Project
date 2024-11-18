#pragma once
#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
    double overdraftLimit;

public:
    CheckingAccount();
    CheckingAccount(string _firstName, string _lastName, string _address, string _phone,
        string _email, int _ID, double _balance, int _withdrawals, int _deposits,
        double _overdraftLimit);
    ~CheckingAccount();

    void setAll(string _firstName, string _lastName, string _address, string _phone, string _email,
        int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit);
    void setOverdraftLimit(double _overdraftLimit);

    double getOverdraftLimit() const;
    void withdraw(double _amount);
    void printInfo();
};


#endif !CHECKING_ACCOUNT_H