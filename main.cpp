#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// //// HWEELLLOOOOO
/// </summary>
class Customer
{
	string firstname;
	string lastname;
	string address;
	int phone;
	string email;

public:

	void PrintInfo()
	{

		cout << "Firstname:" << firstname << endl;
		cout << "Lastname:" << lastname << endl;
		cout << "Address:" << address << endl;
		cout << "Phone:" << phone << endl;
		cout << "Email:" << email << endl;


	}
	void setfirstname(string _firstname)
	{
		firstname = _firstname;


	}

	void setlastname(string _lastname)
	{
		lastname = _lastname;


	}

	void setaddress(string _address)
	{
		address = _address;


	}

	void setphone(int _phone)
	{
		phone = _phone;


	}

	void setemail(string _email)
	{
		email = _email;


	}

	string firstname()
	{

		return firstname;

	}

	string lastname()
	{

		return lastname;

	}

	string address()
	{

		return address;

	}

	int phone()
	{

		return phone;

	}

	string email()
	{

		return email;

	}
};

class Account
{
protected:

	int ID;
	double balance;
	int Withdrawals;
	int Deposits;
	Customer accountCustomer;

public:

	int Deposits(int _Deposits)
	{
		balance = balance + _Deposits;
		Deposits = ++Deposits;

	}

	int Withdrawl(float _Withdrawl)
	{
		if (_Withdrawl <= balance)
		{

			balance = balance - _Withdrawl;
			Withdrawals = ++Withdrawals;

		}


	}

	void PrintInfo()
	{
		accountCustomer.PrintInfo();
		cout << "ID:" << ID << endl;
		cout << "Balance:" << balance << endl;
		cout << "Withdrawals:" << Withdrawals << endl;
		cout << "Deposits:" << Deposits << endl;



	}

};

class CheckingAccount : public Account
{
	double overDraftLimit;



public:

	CheckingAccount(string _firstname, string _lastname, string _address, int _phone, string _email, double _overDraftLimit) : Account()
	{
		overDraftLimit = _overDraftLimit;

	}

	int Withdraw(float amount)
	{
		if (amount <= balance)
		{
			balance = balance - amount;
			Withdrawals = ++Withdrawals;

		}
		else
			if (amount > balance)
			{
				if (amount - balance <= overDraftLimit)
				{
					balance = balance - amount;
					Withdrawals = ++Withdrawals;

				}

			}

	}


};

int main()
{






}