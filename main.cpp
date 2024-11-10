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

	//constructors
	Customer()
	{
		firstName = "";
		lastName = "";
		address = "";
		phone = 0;
		email = "";
	}

	Customer(string _firstName, string _lastName, string _address, int _phone, string _email)
	{
		firstName = _firstName;
		lastName = _lastName;
		address = _address;
		phone = _phone;
		email = _email;
	}

	//setters
	void setAll(string _firstName, string _lastName, string _address, int _phone, string _email)
	{

		firstName = _firstName;
		lastName = _lastName;
		address = _address;
		phone = _phone;
		email = _email;
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

	void setPhone(int _phone)
	{
		phone = _phone;
	}

	void setEmail(string _email)
	{
		email = _email;
	}

	//Getters
	string getFirstName() const
	{
		return firstName;
	}

	string getLastName() const
	{
		return lastName;
	}

	string getAddress() const
	{
		return address;
	}

	int getPhone() const
	{
		return phone;
	}

	string getEmail() const
	{
		return email;
	}
	
	//methods
	void printInfo() const
	{
		cout << "First name: " << firstName << endl;
		cout << "Last name: " << lastName << endl;
		cout << "Address: " << address << endl;
		cout << "Phone: " << phone << endl;
		cout << "Email: " << email << endl;
	}
};


class Account
{
protected:
	int ID;
	double balance;
	int withdrawals;
	int deposits;
	Customer accountCustomer;

public:

	//Constructors
	Account() : accountCustomer()
	{
		ID = 0;
		balance = 0;
		withdrawals = 0;
		deposits = 0;
	}

	Account(string _firstName, string _lastName, string _address, int _phone, string _email,int _ID, double _balance, int _withdrawals, int _deposits) : accountCustomer(_firstName, _lastName, _address, _phone, _email)
	{
		ID = _ID;
		balance = _balance;
		withdrawals = _withdrawals;
		deposits = _deposits;
	}

	//Setters
	void setAll(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits)
	{
		accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email); //added
		ID = _ID;
		balance = _balance;
		withdrawals = _withdrawals;
		deposits = _deposits;
	}

	void setID(int _ID)
	{
		ID = _ID;
	}

	void setBalance(double _balance)
	{
		//Overdraft validator
		if (_balance < 0)
		{
			int input = -1;
			cout << "OVERDRAFT WARNING: Setting balance to " << _balance << " will overdraft this account." << endl <<
				"Are you sure you'd like to proceed with this change?" << endl <<
				"Please input your answer (1, 2)" << endl <<
				"1: Yes (OVERDRAFT)		2: NO" << endl;

			while (input != 1 && input != 2)
			{
				cin >> input;
				cin.ignore();

				if (input == 1) 
				{
					balance = _balance;
					cout << "Overdraft committed.";
				}

				else if (input == 2) 
				{
					cout << "Overdraft not committed." << endl;
				}

				else
				{
					cout << "Error OVR1: Please enter 1 for YES or 2 for NO, or contact your administrator for help." << endl;
				}
			}
		}

		else if (_balance > 1'000'000'000)
		{
			cout << "The maximum deposit for one transaction is $1 billion USD. Please break up your deposit into multiple transactions, or contact your administrator for help." << endl;
		}

		else
		{
			balance = _balance;
		}
	}

	void setWithdrawals(int _withdrawals)
	{
		if (_withdrawals < 0)
		{
			cout << "Error WTD1: Withdrawals amount cannot be less than 0!";
		}
		else
		{
			withdrawals = _withdrawals;
		}
	}

	void setDeposit(int _deposits)
	{
		if (_deposits < 0)
		{
			cout << "Error DEP1: Deposits amount cannot be less than 0!";
		}
		else
		{
			deposits = _deposits;
		}
	}

	//getters
	int getID() const
	{
		return ID;
	}

	double getBalance() const
	{
		return balance;
	}

	int getWithdrawals() const
	{
		return  withdrawals;

	}

	int getDeposit() const
	{
		return deposits;
	}

	//methods
	void deposit(int _deposits)
	{
		balance = balance + _deposits;
		deposits = ++deposits;
	}

	int withdrawl(double _Withdrawl)
	{
		if (_Withdrawl <= balance)
		{

			balance = balance - _Withdrawl;
			withdrawals = ++withdrawals;
		}
	}

	void printInfo()
	{
		accountCustomer.printInfo();
		cout << "ID:" << ID << endl;
		cout << "Balance:" << balance << endl;
		cout << "withdrawals:" << withdrawals << endl;
		cout << "deposits:" << deposits << endl;
	}

};

class CheckingAccount : public Account
{
	double overdraftLimit;



public:
	
	//Constructors
	CheckingAccount() : Account()
	{
		overdraftLimit = 0;


	}

	CheckingAccount(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits)
	{
		overdraftLimit = _overdraftLimit;

	}

	//Setters
	void setAll(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit) 
	{

		//CHANGE
		accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email); 
		Account::setAll(_ID, _balance, _withdrawals, _deposits);
		overdraftLimit = _overdraftLimit;

	}

	void setOverdraftLimit(double _overdraftLimit)
	{

		overdraftLimit = _overdraftLimit;

	}

	//Getters
	double getOverdraftLimit() const
	{

		return overdraftLimit;

	}

	int withdraw(double amount)
	{
		if (amount <= balance)
		{
			balance = balance - amount;
			withdrawals = ++withdrawals;

		}
		else
			if (amount > balance)
			{
				if (amount - balance <= overdraftLimit)
				{
					balance = balance - amount;
					withdrawals = ++withdrawals;

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

	SavingAccount(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, double _interestrate, int _deposits, double _overdraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, ID, balance, withdrawals, deposits)
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
	//string _firstName, string _lastName, string _address, int _phone, string _email, double _overdraftLimit
	Checking[0].setAll("Anthony", "Munoz", "2551 mcdon street", 9999999999, "Mario@gmail.com", 500, 2500, 0, 0, 100);

	cout << "How much money do you want to deposit:";
	cin >> payment;

	Checking[0].deposit(payment);

	Checking[0].printInfo();


	
}