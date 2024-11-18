#include "CheckingAccount.h"

	//Constructors
	CheckingAccount::CheckingAccount() : Account()
	{
		overdraftLimit = 0;
	}

	CheckingAccount::CheckingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits) // Account constructor already calls customer object
	{
		overdraftLimit = _overdraftLimit;
	}

	CheckingAccount::~CheckingAccount() {}

	//Setters
	void CheckingAccount::setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit)
	{
		Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits);
		overdraftLimit = _overdraftLimit;
	}

	void CheckingAccount::setOverdraftLimit(double _overdraftLimit)
	{
		if (_overdraftLimit < 0)
			cout << "Error ODL1: Overdraft Limit cannot be less than 0. Please try again." << endl;

		else
			overdraftLimit = _overdraftLimit;
	}

	//Getters
	double CheckingAccount::getOverdraftLimit() const
	{
		return overdraftLimit;
	}

	void CheckingAccount::printInfo()
	{
		Account::printInfo();
		cout << "Overdraft Limit: $" << overdraftLimit << endl;
	}

	//Methods
	void CheckingAccount::withdraw(double _amount) //changed to void; no return value
	{
		double minimumBalance = -overdraftLimit;

		if (_amount < 0)
			cout << "Error WTH1: Withdrawal amount cannot be less than 0. Please try again." << endl;

		else if (balance - _amount < minimumBalance)
			cout << "Error WTH3: Withdrawal exceeds the account's balance + overdraft limit. Please try again." << endl;

		else if (_amount >= balance && _amount <= (balance + overdraftLimit)) {
			int input = -1;

			cout << "OVERDRAFT WARNING: Withdrawing $" << _amount << " will overdraft this account to $" << balance - _amount << " and is subject to a $20 service fee." << endl <<
				"Are you sure you'd like to proceed with this change?" << endl <<
				"Please input your answer (1, 2)" << endl <<
				"1: Yes (OVERDRAFT)		2: NO" << endl;

			while (input != 1 && input != 2)
			{
				cin >> input;
				cin.ignore();

				if (input == 1)
				{
					balance = ((balance - _amount) - 20);
					withdrawals++;
					cout << "Overdraft & service fee committed. Your updated balance is $" << balance << endl << endl;
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
			balance -= _amount;
			withdrawals++;
			cout << "$" << _amount << " withdrawn. New balance: $" << balance << endl << endl;

		}
	}

