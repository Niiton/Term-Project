#pragma once
#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

#include "Account.h"

class SavingAccount : public Account
{
    double interestRate;

public:
    SavingAccount();
    SavingAccount(string _firstName, string _lastName, string _address, string _phone,
        string _email, int _ID, double _balance, int _withdrawals, double _interestRate,
        int _deposits, double _overdraftLimit);
    ~SavingAccount();

    void setAll(string _firstName, string _lastName, string _address, string _phone, string _email,
        int _ID, double _balance, int _withdrawals, double _interestRate, int _deposits,
        double _overdraftLimit);
    void setInterestRate(double _interestRate);

    double getInterestRate() const;
    void payInterest();

    void printInfo();
};

#endif !SAVING_ACCOUNT_H