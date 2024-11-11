#include <iostream>
#include <string>
using namespace std;


//system cls to clear previous screens in output, good for good menu
//input validation needs to be reviewed
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

	Account(string _firstName, string _lastName, string _address, int _phone, string _email,int _ID, double _balance, int _withdrawals, int _deposits) : accountCustomer(_firstName, _lastName, _address, _phone, _email) //No need to call setAll with initializers
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

	//Setters
	void setAll(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits)
	{
		accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email); //added
		ID = _ID;
		balance = _balance;
		withdrawals = _withdrawals;
		deposits = _deposits;
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

		else
		{
			balance = _balance;
		}
	}

	void setID(int _ID)
	{
		if (_ID < 0)
		{
			cout << "Error SID1: Withdrawals amount cannot be less than 0!";
		}
		else
		{
			ID = _ID;
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

		// Transfers an account to another existing account
	void transferAccountOwner(Customer _customer)
	{
		accountCustomer = _customer;
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
	void deposit(double _amount)
	{
		if (_amount <= 0)
			cout << "Error DEP1: Deposit amount cannot be less than 0. Please try again." << endl;

		else if (_amount > 1'000'000'000)
			cout << "The maximum deposit for one transaction is $1 billion USD. Please break up your deposit into multiple transactions, or contact your administrator for help." << endl;
		
		else
		{
			balance += _amount;
			deposits++;
		}
	}

	void withdraw(double _amount) //changed to void; no return value
	{
		if (_amount < 0)
			cout << "Error WTH1: Withdrawal amount cannot be less than 0. Please try again." << endl;

		else if (_amount > balance)
			cout << "Error WTH2: Withdrawal amount cannot exceed the account's balance. Please try again." << endl;

		else
		{
			balance -= _amount;
			withdrawals++;
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

	CheckingAccount(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits) // Account constructor already calls customer object
	{
		overdraftLimit = _overdraftLimit;
	}

	//Setters
	void setAll(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit)
	{
		Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits);
		overdraftLimit = _overdraftLimit;
	}

	void setOverdraftLimit(double _overdraftLimit)
	{
		if (_overdraftLimit < 0)
			cout << "Error ODL1: Overdraft Limit cannot be less than 0. Please try again." << endl;

		else
			overdraftLimit = _overdraftLimit;
	}

	//Getters
	double getOverdraftLimit() const
	{
		return overdraftLimit;
	}

	//Methods
	void withdraw(double _amount) //changed to void; no return value
	{
		double minimumBalance = -overdraftLimit;
		
		if (_amount < 0)
			cout << "Error WTH1: Withdrawal amount cannot be less than 0. Please try again." << endl;

		else if (_amount - balance < minimumBalance)
			cout << "Error WTH3: Withdrawal exceeds the account's balance + overdraft limit. Please try again." << endl;

		else if (_amount > balance && _amount < (balance + overdraftLimit)) {
			int input = -1;

			cout << "OVERDRAFT WARNING: Withdrawing " << _amount << " will overdraft this account to $" << _amount - balance << " and is subject to a $20 service fee." << endl <<
				"Are you sure you'd like to proceed with this change?" << endl <<
				"Please input your answer (1, 2)" << endl <<
				"1: Yes (OVERDRAFT)		2: NO" << endl;

			while (input != 1 && input != 2)
			{
				cin >> input;
				cin.ignore();

				if (input == 1)
				{
					balance -= (20 - _amount);
					withdrawals++;
					cout << "Overdraft & service fee committed.";
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
		}
	}
};

class SavingAccount : public Account
{
	double interestRate;

public:

	//Constructors
	SavingAccount() : Account()
	{
		interestRate = 0;
	}

	SavingAccount(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, int _withdrawals, double _interestRate, int _deposits, double _overdraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits)
	{
		interestRate = 0;
	}

	//Setters
	void setAll(string _firstName, string _lastName, string _address, int _phone, string _email, int _ID, double _balance, int _withdrawals, double _interestRate, int _deposits, double _overdraftLimit)
	{
		Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits);
		interestRate = _interestRate;
	}

	void setInterestRate(double _interestRate)
	{
		interestRate = _interestRate;
	}

	//Getters
	double getInterestRate() const
	{
		return interestRate;

	}

	//Methods
	void payInterest()
	{
		balance += (balance*interestRate);
	}
};

void printMainMenu() {
	
	cout << "____________________________________________" << endl << endl;


	cout << "\tAccount Administrator System" << endl << endl;
	cout << "To manually navigate the menu, please input the corresponding number to the menu choice." << endl << endl;

	cout <<
		"0- Exit" << endl <<
		"1- View and Modify Accounts by List" << endl <<
		"2- View and Modify by Search" << endl <<
		"3- Create an Account" << endl << endl <<

		"____________________________________________" << endl << endl <<

		"Enter an option 0-3: ";

}

int main()
{
	double payment;
	CheckingAccount Checking[10];
	SavingAccount Saving[10];
	int defaultOverdraftLimit = 500;

	Checking[0].setAll("Anthony", "Munoz", "2551 mcdon street", 9999999999, "Mario@gmail.com", 1, 2500, 0, 0, 100);
	Checking[1].setAll("Ethan", "Gonzalez Jamison", "4400 Wacdon St", 5865552986, "Ethan@Wakudon.com", 2, 50'000, 5, 2, 10'000);

	int checkingCount = 2;
	int savingCount = 0;
	int accountCounter = checkingCount + savingCount;

	//string _firstName, string _lastName, string _address, int _phone, string _email, double _overdraftLimit

	int menuInput = -1;

	while (menuInput != 0) {

		/* cout << "Account Management System" << endl;

		cout << "To navigate the menu, please input the corresponding number to the menu choice." << endl << endl;

		cout <<
		"0- Exit" << endl <<
		"1- View and Modify Accounts" << endl <<
		"2- View and Modify by Search" << endl <<
		"3- Create an Account" << endl <<

		"Enter an option 0-3: ";

			"Enter an option 0-3: "; */

		printMainMenu();

		cin >> menuInput;
		cin.ignore();

		switch (menuInput)
		{
		case 0:
			cout << "Thank you for using Account Management System!" << endl;
			return 0;
			break;

		case 1:
			//	for (int i=0; )
			break;

		case 2:

			break;

		case 3:



			break;

		default:

			cout << "Error MENI1: Invalid input. Please try again." << endl << endl;
			continue;
		}

	}
}