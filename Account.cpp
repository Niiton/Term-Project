#include "Account.h"


	//Constructors
	Account::Account() : accountCustomer()
	{
		ID = 0;
		balance = 0;
		withdrawals = 0;
		deposits = 0;
	}

	Account::Account(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits) : accountCustomer(_firstName, _lastName, _address, _phone, _email) //No need to call setAll with initializers
	{
		ID = _ID;
		if (ID < 0)
			ID = 0;

		balance = _balance;
		if (balance < 0)
			balance = 0;

		withdrawals = _withdrawals;
		if (withdrawals < 0)
			withdrawals = 0;

		deposits = _deposits;
		if (deposits < 0)
			deposits = 0;
	}

	Account::~Account() {}


	//Setters
	void Account::setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits)
	{
		accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email); //added
		ID = _ID;
		balance = _balance;
		withdrawals = _withdrawals;
		deposits = _deposits;
	}

	void Account::setCustomerDetails(const string& parameter, const string& newValue)
	{
		if (parameter == "firstName") {
			accountCustomer.setFirstName(newValue);
		}
		else if (parameter == "lastName") {
			accountCustomer.setLastName(newValue);
		}
		else if (parameter == "address") {
			accountCustomer.setAddress(newValue);
		}
		else if (parameter == "email") {
			accountCustomer.setEmail(newValue);
		}
		else if (parameter == "phone")
		{
			accountCustomer.setPhone(newValue);
		}
		else
		{
			cout << "Invalid parameter name for string input." << endl;
		}
	}

	void Account::setBalance(double _balance)
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

		else
		{
			balance = _balance;
		}
	}

	void Account::setID(int _ID)
	{
		if (_ID < -1)
		{
			cout << "Error SID1: Withdrawals amount cannot be less than 0, and -1 is for deleted accounts only!";
		}
		else
		{
			ID = _ID;
		}
	}

	void Account::setWithdrawals(int _withdrawals)
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

	void Account::setDeposits(int _deposits)
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

	// Transfers an account to another existing account
	void Account::transferAccountOwner(Customer _customer)
	{
		accountCustomer = _customer;
	}

	//getters

	string Account::getCustomerDetails(const string& parameter) const
	{
		if (parameter == "firstName") {
			return accountCustomer.getFirstName();
		}
		else if (parameter == "lastName") {
			return accountCustomer.getLastName();
		}
		else if (parameter == "address") {
			return accountCustomer.getAddress();
		}
		else if (parameter == "email") {
			return accountCustomer.getEmail();
		}
		else if (parameter == "phone")
		{
			return accountCustomer.getPhone();
		}

		else
		{
			cout << "Invalid parameter name for string output." << endl;
		}
	}

	int Account::getID() const
	{
		return ID;
	}

	double Account::getBalance() const
	{
		return balance;
	}

	int Account::getWithdrawals() const
	{
		return withdrawals;
	}

	int Account::getDeposits() const
	{
		return deposits;
	}

	//methods
	void Account::deposit(double _amount)
	{
		if (_amount <= 0)
			cout << "Error DEP1: Deposit amount cannot be less than 0. Please try again." << endl;

		else if (_amount > 1'000'000'000)
			cout << "The maximum deposit for one transaction is $1 billion USD. Please break up your deposit into multiple transactions, or contact your administrator for help." << endl;

		else
		{
			balance += _amount;
			deposits++;
			cout << "$" << _amount << " deposited. New balance: " << balance << endl << endl;
		}
	}

	void Account::withdraw(double _amount) //changed to void; no return value
	{
		if (_amount < 0)
			cout << "Error WTH1: Withdrawal amount cannot be less than 0. Please try again." << endl;

		else if (_amount > balance)
			cout << "Error WTH2: Withdrawal amount cannot exceed the account's balance. Please try again." << endl;

		else
		{
			balance -= _amount;
			withdrawals++;
			cout << "$" << _amount << " withdrawn. New balance: " << balance << endl << endl;
		}
	}

	void Account::printInfo()
	{
		accountCustomer.printInfo();
		cout << "ID: " << ID << endl;
		cout << "Balance: $" << balance << endl;
		cout << "Withdrawals: " << withdrawals << endl;
		cout << "Deposits: " << deposits << endl;
	}

