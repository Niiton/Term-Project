#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Customer.h"

class Account
{
protected:
    int ID;
    double balance;
    int withdrawals;
    int deposits;
    Customer accountCustomer;

public:
    Account();
    Account(string _firstName, string _lastName, string _address, string _phone, string _email,
            int _ID, double _balance, int _withdrawals, int _deposits);
    ~Account();

    void setAll(string _firstName, string _lastName, string _address, string _phone, string _email,
                int _ID, double _balance, int _withdrawals, int _deposits);
    void setCustomerDetails(const string &parameter, const string &newValue);
    void setBalance(double _balance);
    void setID(int _ID);
    void setWithdrawals(int _withdrawals);
    void setDeposits(int _deposits);
    void transferAccountOwner(Customer _customer);

    string getCustomerDetails(const string &parameter) const;
    int getID() const;
    double getBalance() const;
    int getWithdrawals() const;
    int getDeposits() const;

    void deposit(double _amount);
    void withdraw(double _amount);
    void printInfo();
};

#endif !ACCOUNT_H