#pragma once
#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer
{
    string firstName;
    string lastName;
    string address;
    string phone;
    string email;

public:
    Customer();
    Customer(string _firstName, string _lastName, string _address, string _phone, string _email);
    ~Customer();

    void setAll(string _firstName, string _lastName, string _address, string _phone, string _email);
    void setFirstName(string _firstName);
    void setLastName(string _lastName);
    void setAddress(string _address);
    void setPhone(string _phone);
    void setEmail(string _email);

    string getFirstName() const;
    string getLastName() const;
    string getAddress() const;
    string getPhone() const;
    string getEmail() const;

    void printInfo() const;
};

#endif !_CUSTOMER_H