#include "SavingAccount.h"

	//Constructors
	SavingAccount::SavingAccount() : Account()
	{
		interestRate = 0;
	}

	SavingAccount::SavingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, double _interestRate, int _deposits, double _overdraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits)
	{
		interestRate = 0;
	}

	SavingAccount::~SavingAccount() {}

	//Setters
	void SavingAccount::setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, double _interestRate, int _deposits, double _overdraftLimit)
	{
		Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits);
		interestRate = _interestRate;
	}

	void SavingAccount::setInterestRate(double _interestRate)
	{
		interestRate = _interestRate;
	}

	//Getters
	double SavingAccount::getInterestRate() const
	{
		return interestRate;

	}

	void SavingAccount::printInfo() {
		Account::printInfo();
		cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
	}

	//Methods
	void SavingAccount::payInterest()
	{
		balance += (balance * interestRate);

		cout << "Interest rate " << interestRate * 100 << "% applied." << endl <<
			"New balance: $" << balance << endl << endl;
	}
