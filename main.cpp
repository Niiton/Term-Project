#include <iostream>
#include <string>
using namespace std;


//system cls to clear previous screens in output, good for good menu
//input validation needed 
//need to change the nape of cpp and header files.

class Customer
{
	string firstName;
	string lastName;
	string address;
	int phone;
	string email;

public:



	Customer()
	{
		firstName = "";
		lastName = "";
		address = "";
		phone = "";
		email = "";


	}

	Customer(string _firstName, string _lastName, string _address, string _phone, string _email)
	{
		firstName = _firstName;
		lastName = _lastName;
		address = _address;
		phone = _phone;
		email = _email;

	}

	void setall(string _firstName, string lastName, string _address, string _phone, string _email)
	{

		firstName = _firstName;
		lastName = lastName;
		address = _address;
		phone = _phone;
		email = _email;

	}

	void PrintInfo() const
	{

		cout << "firstName:" << firstName << endl;
		cout << "lastName:" << lastName << endl;
		cout << "Address:" << address << endl;
		cout << "Phone:" << phone << endl;
		cout << "Email:" << email << endl;


	}
	void setFirstName(string _firstName)
	{
		firstName = _firstName;


	}

	void setLastName(string _lastName)
	{
		lastName = _lastName;


	}

	void setAddress(string _address)
	{
		address = _address;


	}

	void setPhone(string _phone)
	{
		phone = _phone;


	}

	void setemail(string _email)
	{
		email = _email;


	}

	string getFirstName() const
	{

		return firstName;

	}

	string getLastName() const
	{

		return lastName;

	}

	string getaddress() const
	{

		return address;

	}

	string getphone() const
	{

		return phone;

	}

	string getemail() const
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

	Account()
	{
		ID = 0;
		balance = 0;
		Withdrawals = 0;
		Deposits = 0;


	}

	Account(string _firstName, string _lastName, string _address, string _phone, string _email,int _ID, double _balance, int _Withdrawals, int _Deposits) 
	{
		accountCustomer.setall( _firstName, _lastName,  _address, _phone,  _email);
		ID = _ID;
		balance = _balance;
		Withdrawals = _Withdrawals;
		Deposits = _Deposits;



	}

	void setall(int _ID, double _balance, int _Withdrawals, int _Deposits)
	{
		ID = _ID;
		balance = _balance;
		Withdrawals = _Withdrawals;
		Deposits = _Deposits;


	}

	void Deposit(int _Deposits)
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

	void setID(int _ID)
	{
		ID = _ID;


	}

	void setbalance(double _balance)
	{
		balance = _balance;


	}

	void setWithdrawals(int _Withdrawals)
	{
		Withdrawals = _Withdrawals;


	}

	void setDeposit(int _Deposits)
	{
		Deposits = _Deposits;


	}

	int getID() const
	{

		return ID;

	}

	double getbalance() const
	{

		return balance;

	}

	int getWithdrawals() const
	{
		return  Withdrawals;

	}

	int getDeposit() const
	{

		return Deposits;

	}

};

class CheckingAccount : public Account
{
	double overDraftLimit;



public:



	CheckingAccount() :Account()
	{
		overDraftLimit = 0;


	}


	CheckingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _Withdrawals, int _Deposits, double _overDraftLimit) : Account( _firstName,  _lastName,  _address,  _phone,  _email,ID, balance, Withdrawals, Deposits)
	{
		overDraftLimit = _overDraftLimit;

	}

	void setall(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _Withdrawals, int _Deposits, double _overDraftLimit) 
	{
		accountCustomer.setall(_firstName, _lastName, _address, _phone, _email); 
		Account::setall(_ID, _balance, _Withdrawals, _Deposits);
		overDraftLimit = _overDraftLimit;

	}

	void setoverdraftlimit(double _overDraftLimit)
	{

		overDraftLimit = _overDraftLimit;

	}

	double getoverDraftLimit() const
	{

		return overDraftLimit;

	}

	int Withdraw(float& amount)
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

//need to fix saving account passing
class SavingAccount : public Account
{
	double interestRate;

public:
	SavingAccount() : Account()
	{
		interestRate = 0;


	}

	SavingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, double _interestrate, int _Deposits, double _overDraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, ID, balance, Withdrawals, Deposits)
	{
		interestRate = 0;


	}

	void setall(string _firstName, string _lastName, string _address, int _phone, string _email, double _interestrate)
	{

		interestRate = _interestrate;
	}

	void payIntrest()
	{
		balance = interestRate * balance;


	}

	void setinterestrate(double _interestRate)
	{
		interestRate = _interestRate;


	}

	double getinterestRate() const
	{
		return interestRate;

	}
};

int main()
{
	double payment;
	CheckingAccount Checking[5];
	SavingAccount Saving[5];
	//string _firstName, string _lastName, string _address, int _phone, string _email, double _overDraftLimit
	Checking[0].setall("Anthony", "Munoz", "2551 mcdon street", "2222222", "Mario@gmail.com", 500, 2500, 0, 0, 100);

	cout << "How much money do you want to deposit:";
	cin >> payment;

	Checking[0].Deposit(payment);

	Checking[0].PrintInfo();


	
}