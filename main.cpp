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
	string phone;
	string email;

public:

	//constructors
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

	~Customer() {}

	//setters
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email)
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

	void setPhone(string _phone)
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

	string getPhone() const
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

	Account(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits) : accountCustomer(_firstName, _lastName, _address, _phone, _email) //No need to call setAll with initializers
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

	~Account() {}


	//Setters
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits)
	{
		accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email); //added
		ID = _ID;
		balance = _balance;
		withdrawals = _withdrawals;
		deposits = _deposits;
	}

	void setCustomerDetails(const string& parameter, const string& newValue)
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
		if (_ID < -1)
		{
			cout << "Error SID1: Withdrawals amount cannot be less than 0, and -1 is for deleted accounts only!";
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

	void setDeposits(int _deposits)
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

	string getCustomerDetails(const string& parameter) const
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
		return withdrawals;
	}

	int getDeposits() const
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
			cout << "$" << _amount << " deposited. New balance: " << balance << endl << endl;
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
			cout << "$" << _amount << " withdrawn. New balance: " << balance << endl << endl;
		}
	}

	void printInfo()
	{
		accountCustomer.printInfo();
		cout << "ID: " << ID << endl;
		cout << "Balance: $" << balance << endl;
		cout << "Withdrawals: " << withdrawals << endl;
		cout << "Deposits: " << deposits << endl;
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

	CheckingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits) // Account constructor already calls customer object
	{
		overdraftLimit = _overdraftLimit;
	}

	~CheckingAccount() {}

	//Setters
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, int _deposits, double _overdraftLimit)
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

	void printInfo()
	{
		Account::printInfo();
		cout << "Overdraft Limit: $" << overdraftLimit << endl;
	}

	//Methods
	void withdraw(double _amount) //changed to void; no return value
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

	SavingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, double _interestRate, int _deposits, double _overdraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawals, _deposits)
	{
		interestRate = 0;
	}

	~SavingAccount() {}

	//Setters
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawals, double _interestRate, int _deposits, double _overdraftLimit)
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

	void printInfo() {
		Account::printInfo();
		cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
	}

	//Methods
	void payInterest()
	{
		balance += (balance * interestRate);

		cout << "Interest rate " << interestRate * 100 << "% applied." << endl <<
			"New balance: $" << balance << endl << endl;
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

void printViewOptions()
{
	cout << endl << "Which accounts would you like to view?" << endl << endl;
	cout << "0- Back" << endl;
	cout << "1- Checking Accounts" << endl;
	cout << "2- Saving Accounts" << endl << endl;

	cout << "Please select an option (0-3): ";
}

void printModifyOptionsChecking()
{
	cout << endl << "1- Cash Deposit \t2- Cash Withdraw" << endl <<
		"3- First Name \t4- Last Name" << endl <<
		"5- Address \t6- Phone Number" << endl <<
		"7- Email \t8- ID" << endl <<
		"9- Balance \t10- Total Withdrawals" << endl <<
		"11- Total Deposits \t12- Overdraft Limit" << endl <<
		"13- ALL" << endl <<
		"14- DELETE (CAUTION!)" << endl <<
		"0- Exit" << endl << endl;

	cout << "Please enter your selection: ";
}
void printModifyOptionsSaving()
{

	cout << endl << "What would you like to do or modify?" << endl << endl;
	cout << "1- Cash Deposit \t2- Cash Withdraw" << endl <<
		"3- Compound Interest \t4- First Name" << endl <<
		"5- Last Name \t6- Address" << endl <<
		"7 - Phone Number \t8- Email" << endl <<
		"9- ID \t10- Balance" << endl <<
		"11- Total Withdrawals \t12- Total Deposits" << endl <<
		"13- Overdraft Limit \t14- ALL" << endl <<
		"15- DELETE (CAUTION!)" << endl <<
		"0- Exit" << endl << endl;

	cout << "Please enter your selection: ";
}

void deposit(CheckingAccount& acc)
{
	double amt;
	cout << "Enter an amount to deposit: ";
	cin >> amt; cin.ignore();

	acc.deposit(amt);
}

void deposit(SavingAccount& acc)
{
	double amt;
	cout << "Enter an amount to deposit: ";
	cin >> amt; cin.ignore();

	acc.deposit(amt);
}

void withdraw(CheckingAccount& acc)
{
	double amt;
	cout << "Enter an amount to withdraw: ";
	cin >> amt; cin.ignore();

	acc.withdraw(amt);
}

void withdraw(SavingAccount& acc)
{
	double amt;
	cout << "Enter an amount to withdraw: $";
	cin >> amt; cin.ignore();

	acc.withdraw(amt);
}

void getAndModAllInputChecking(CheckingAccount& Checking)
{
	string firstName, lastName, address, email, phone;
	int ID, withdrawals, deposits;
	double balance, overdraftLimit;

	cout << endl << "Enter a new first name: ";
	getline(cin, firstName);

	cout << endl << "Enter a new last name: ";
	getline(cin, lastName);

	cout << endl << "Enter a new address: ";
	getline(cin, address);

	cout << endl << "Enter a new phone number: ";
	cin >> phone;
	cin.ignore();

	cout << endl << "Enter a new email address: ";
	getline(cin, email);

	cout << endl << "Enter a new customer ID: ";
	cin >> ID; cin.ignore();

	cout << endl << "Enter a new balance: ";
	cin >> balance; cin.ignore();

	cout << endl << "Enter a new withdrawals amount: ";
	cin >> withdrawals; cin.ignore();

	cout << endl << "Enter a new deposits amount: ";
	cin >> deposits; cin.ignore();

	cout << endl << "Enter a new overdraft limit: ";
	cin >> overdraftLimit; cin.ignore();

	Checking.setAll(firstName, lastName, address, phone, email, ID, balance, withdrawals, deposits, overdraftLimit);
}

void getAndModAllInputSaving(SavingAccount& Saving)
{
	string firstName, lastName, address, email, phone;
	int ID, withdrawals, deposits;
	double balance, overdraftLimit, interestRate;

	cout << endl << "Enter a new first name: ";
	getline(cin, firstName);

	cout << endl << "Enter a new last name: ";
	getline(cin, lastName);

	cout << endl << "Enter a new address: ";
	getline(cin, address);

	cout << endl << "Enter a new phone number: ";
	cin >> phone;
	cin.ignore();

	cout << endl << "Enter a new email address: ";
	getline(cin, email);

	cout << endl << "Enter a new customer ID: ";
	cin >> ID; cin.ignore();

	cout << endl << "Enter a new balance: ";
	cin >> balance; cin.ignore();

	cout << endl << "Enter a new withdrawals amount: ";
	cin >> withdrawals; cin.ignore();

	cout << endl << "Enter a new deposits amount: ";
	cin >> deposits; cin.ignore();

	cout << endl << "Enter a new overdraft limit: ";
	cin >> overdraftLimit; cin.ignore();

	cout << endl << "Enter a new interest rate: ";
	cin >> interestRate; cin.ignore();

	Saving.setAll(firstName, lastName, address, phone, email, ID, balance, withdrawals, interestRate, deposits, overdraftLimit);
}

//Rearranges checking accounts if an account is deleted, explicit use in deleteAccount();
void rearrangeCheckingAccs(CheckingAccount checking[], int checkingCount)
{
	CheckingAccount emptyChecking;
	emptyChecking.setID(-1);

	//Prevent gaps in Checking[] after deletion, and send deleted items to the end
	for (int i = 0; i < checkingCount; i++)
	{
		if (checking[i].getID() == -1)
		{
			checking[i] = checking[i + 1];
			checking[i + 1] = emptyChecking;
		}
	}

	for (int i = 0; i < checkingCount; i++)
	{
		if (checking[i].getID() == -1)
			checking[i].setID(0);
	}

	cout << "Accounts Rearranged!" << endl << endl;
}

void deleteAccount(CheckingAccount checkingArr[], int& checkingCount, int accToModify)
{
	checkingArr[accToModify].setAll("", "", "", "", "", -1, 0, 0, 0, 0); // Clear the account data and mark it as deleted using ID -1
	cout << "Account Deleted!" << endl;
	rearrangeCheckingAccs(checkingArr, checkingCount);
	checkingCount--;
}

//Rearranges saving accounts if an account is deleted, explicit use in deleteAccount();
void rearrangeCheckingAccs(SavingAccount saving[], int savingCount)
{
	SavingAccount emptySaving;
	emptySaving.setID(-1);

	//Prevent gaps in Saving[] after deletion, and send deleted items to the end
	for (int i = 0; i < savingCount; i++)
	{
		if (saving[i].getID() == -1)
		{
			saving[i] = saving[i + 1];
			saving[i + 1] = emptySaving;
		}
	}
}

void deleteAccount(SavingAccount savingArr[], int& savingCount, int accToModify)
{
	savingArr[accToModify].setAll("", "", "", "", "", -1, 0, 0, 0, 0, 0); // Clear the account data and mark it as deleted using ID -1
	cout << "Account Deleted!" << endl;
	rearrangeCheckingAccs(savingArr, savingCount);
	savingCount--;
}

int main()
{
	CheckingAccount Checking[10];
	SavingAccount Saving[10];
	int defaultOverdraftLimit = 500;
	bool endLoop = false;

	Checking[0].setAll("Anthony", "Munoz", "2551 mcdon street", "9999999999", "Mario@gmail.com", 1, 2500, 0, 0, 100);
	Checking[1].setAll("Ethan", "Gonzalez Jamison", "4400 Wacdon St", "5865552986", "Ethan@Wakudon.com", 2, 50'000, 5, 2, 10'000);
	Checking[2].setAll("Ethan", "Gonzalez Jamison", "4400 Wacdon St", "5865552986", "Ethan@Wakudon.com", 3, 50'000, 5, 2, 10'000);

	Saving[0].setAll("Rock", "Johnson", "2554 Ocean Dr", "(904) 555-1475", "Rock@RockEnterprises.rok", 4, 900'000, 4026, .10, 9867, 10'000);
	Saving[1].setAll("Jock", "Ronson", "2556 Ocean Dr", "(904) 555-1476", "Jock@RonEnterprises.jok", 5, 900'000, 864, .08, 687, 9'000);

	int checkingCount = 3;
	int savingCount = 2;
	int accountCounter = checkingCount + savingCount;

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
			//exit
			cout << "Thank you for using Account Management System!" << endl;
			return 0;
			break;

			//Menu Op 1
		case 1:

			//clr terminal here
			cout << "____________________________________________" << endl << endl;
			cout << "\tAccount List" << endl << endl;

			int viewAccountInput;

			printViewOptions();

			cin >> viewAccountInput;
			cin.ignore();

			//Input Validation for Account View Options
			if (viewAccountInput < 0 || viewAccountInput > 3)
			{
				cout << "Error VACI1: Invalid input. Please try again." << endl << endl;
			}

			//print new menu for decisions
			while (viewAccountInput >= 0 && viewAccountInput < 3) {

				endLoop = false;

				switch (viewAccountInput)
				{

					//exit
				case 0:

					cout << "Going back..." << endl;
					endLoop = true;
					break;

					//View Checking Accounts
				case 1:

					cout << "Checking Accounts:" << endl << endl;

					if (checkingCount == 0) {
						cout << "No Checking Accounts found!" << endl <<
							"Please create an account, or choose a different account type." << endl;
						break;
					}

					for (int i = 0; i < checkingCount; i++)
					{
						cout << "Checking Account " << i + 1 << ":" << endl;
						Checking[i].printInfo();
						cout << endl << endl;
					}
					//////////////////////////
					// HERE AND PAST ARE MODIFY OPTIONS FOR CHECKING ACCOUNTS UNTIL CASE 2
					//////////////////////////
					int accToModify;
					cout << "Enter 0 to exit, or enter the Checking Account number to modify: ";
					cin >> accToModify; cin.ignore();
					cout << endl;

					if (accToModify > checkingCount || accToModify < 0)
					{
						cout << "Error MOD1: Please enter a checking account number displayed before account details, or press 0 to exit." << endl << endl;
					}

					while (accToModify >= 0 && accToModify <= checkingCount)
					{
						//Exit
						if (accToModify == 0)
						{
							cout << "Exiting..." << endl;
							endLoop = true; break;
						}
						//Modify Checking
						else if (accToModify <= checkingCount)
						{
							accToModify--;
							cout << endl;
							Checking[accToModify].printInfo();
							int modAccInput;

							//all input to modify from input
							string modStringInput;
							int modIntInput;
							double modDoubleInput;


							do
							{
								printModifyOptionsChecking();

								cin >> modAccInput; cin.ignore();
								cout << endl << endl;

								if (modAccInput < 0 || modAccInput > 14)
								{
									cout << "Invalid Input! Please try again." << endl << endl;
									continue;
								}

								if (modAccInput == 0) 
								{
									endLoop = true;
									break;
								}

								switch (modAccInput)
								{
								case 1:
									deposit(Checking[accToModify]);
									endLoop = true;
									break;
								case 2:
									withdraw(Checking[accToModify]);
									endLoop = true; 
									break;
								case 3:
									cout << "Enter the updated first name: ";
									getline(cin, modStringInput);

									Checking[accToModify].setCustomerDetails("firstName", modStringInput);

									cout << "First name updated to " << Checking[accToModify].getCustomerDetails("firstName") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 4:
									cout << "Enter the updated last name: ";
									getline(cin, modStringInput);

									Checking[accToModify].setCustomerDetails("lastName", modStringInput);

									cout << "Last name updated to " << Checking[accToModify].getCustomerDetails("lastName") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 5:
									cout << "Enter the updated address: ";
									getline(cin, modStringInput);

									Checking[accToModify].setCustomerDetails("address", modStringInput);

									cout << "Address updated to " << Checking[accToModify].getCustomerDetails("address") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 6:
									cout << "Enter the updated phone number: ";
									getline(cin, modStringInput);

									Checking[accToModify].setCustomerDetails("phone", modStringInput);

									cout << endl << "Phone number updated to " << Checking[accToModify].getCustomerDetails("phone") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 7:
									cout << "Enter the updated email address: ";
									getline(cin, modStringInput);

									Checking[accToModify].setCustomerDetails("email", modStringInput);

									cout << "Email address updated to " << Checking[accToModify].getCustomerDetails("email") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 8:
									cout << "Enter a new ID: ";
									cin >> modIntInput;
									Checking[accToModify].setID(modIntInput);

									cout << "ID updated to " << Checking[accToModify].getID() << "." << endl << endl;
									modIntInput = 0;
									endLoop = true;
									break;

								case 9:
									cout << "Enter account's modified balance: ";
									cin >> modDoubleInput;
									Checking[accToModify].setBalance(modDoubleInput);

									cout << "Balance updated to " << Checking[accToModify].getBalance() << "." << endl << endl;
									modDoubleInput = 0;
									endLoop = true;
									break;

								case 10:
									cout << "Enter a new amount of withdrawals for the account: ";
									cin >> modIntInput;
									Checking[accToModify].setWithdrawals(modIntInput);

									cout << "Withdrawals updated to " << Checking[accToModify].getWithdrawals() << "." << endl << endl;
									modIntInput = 0;
									endLoop = true;
									break;

								case 11:
									cout << "Enter a new amount of deposits for the account: ";
									cin >> modIntInput;
									Checking[accToModify].setDeposits(modIntInput);

									cout << "Deposits updated to " << Checking[accToModify].getDeposits() << "." << endl << endl;
									modIntInput = 0;
									endLoop = true;
									break;

								case 12:
									cout << "Enter a new overdraft limit: ";
									cin >> modIntInput;
									Checking[accToModify].setID(modIntInput);

									cout << "ID updated to " << Checking[accToModify].getID() << "." << endl << endl;
									modIntInput = 0;
									endLoop = true;
									break;

								case 13:
									int modAllChecker;
									cout << "CAUTION: You are now setting ALL elements of the checking account. Would you like to proceed?" << endl <<
										"Enter 0 for NO (Go back) \t Enter 1 for YES (MODIFY ALL ELEMENTS): ";

									cin >> modAllChecker; cin.ignore();

									if (modAllChecker < 0 || modAllChecker > 1)
									{
										cout << "Error MALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
										modAccInput = -1; // Trips the while loop below
									}

									else if (modAllChecker == 0)
									{
										cout << "Returning to previous menu..." << endl << endl;
										modAccInput = -1; // Trips the while loop below
										break;
									}

									else if (modAllChecker == 1)
									{
										getAndModAllInputChecking(Checking[accToModify]);
										cout << endl << "Account Information Modified. Any invalid inputs are set to default. Please double-check the account and modify accordingly if needed." << endl << endl;
										endLoop = true;
										break;
									}

									else
									{
										cout << "FMALL1: Input Error. Please try again. If the problem persists, please contact IT." << endl << endl;
										modAccInput = -1;
									}
									break;

								case 14:

									int deleteAccInput;
									cout << "WARNING: Are you sure you'd like to liquify and delete this account?" << endl <<
										"DELETING ACCOUNTS IS IRREVESIBLE!" << endl;
									cout << "0- No, take me back." << endl <<
										"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

									cout << "Enter input here: ";
									cin >> deleteAccInput;

									if (deleteAccInput < 0 || deleteAccInput > 1)
									{
										cout << "Error DALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
										modAccInput = -1; // Trips the while loop below
									}

									else if (deleteAccInput == 0)
									{
										cout << "Returning to previous menu..." << endl << endl;
										modAccInput = -1; // Trips the while loop below
										break;
									}
									else if (deleteAccInput == 1)
									{
										cout << endl << "LAST WARNING: You are about to delete the customer's account. Are you sure you'd like to proceed?" << endl;
										cout << "0- No, take me back." << endl <<
											"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

										cout << "Enter input here: ";
										cin >> deleteAccInput;

										if (deleteAccInput < 0 || deleteAccInput > 1)
										{
											cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (deleteAccInput == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}

										else if (deleteAccInput == 1)
										{
											cout << "Deleting Account..." << endl;
											deleteAccount(Checking, checkingCount, accToModify);
											endLoop = true;
										}

										break;
									}
								}
							} while (modAccInput < 0 || modAccInput > 14);
							break;
						}
					}
					if (endLoop) break;

					//View Savings Accounts
				case 2:

					cout << "Saving Accounts:" << endl << endl;

					if (savingCount == 0) {
						cout << "No Saving Accounts found!" << endl <<
							"Please create an account, or choose a different account type." << endl;
						break;
					}

					for (int i = 0; i < savingCount; i++)
					{
						cout << "Saving Account " << i + 1 << ":" << endl;
						Saving[i].printInfo();
						cout << endl << endl;
					}
					//////////////////////////
					// HERE AND PAST ARE MODIFY OPTIONS FOR SAVING ACCOUNTS UNTIL CASE 2
					//////////////////////////
					cout << "Enter 0 to exit, or enter the saving Account number to modify: ";
					cin >> accToModify; cin.ignore();
					cout << endl;

					if (accToModify > savingCount || accToModify < 0)
					{
						cout << "Error MOD1: Please enter a saving account number displayed before account details, or press 0 to exit." << endl << endl;
					}

					while (accToModify >= 0 && accToModify <= savingCount)
					{
						//Exit
						if (accToModify == 0)
						{
							cout << "Exiting..." << endl;
							endLoop = true; break;
						}
						//Modify saving
						else if (accToModify <= savingCount)
						{
							accToModify--;
							cout << endl;
							Saving[accToModify].printInfo();
							int modAccInput;

							//all input to modify from input
							string modStringInput;
							int modIntInput;
							double modDoubleInput;


							do
							{
								printModifyOptionsSaving();

								cin >> modAccInput; cin.ignore();
								cout << endl << endl;

								if (modAccInput < 0 || modAccInput > 15)
								{
									cout << "Invalid Input! Please try again." << endl << endl;
									continue;
								}

								switch (modAccInput)
								{
								case 1:
									deposit(Saving[accToModify]);
									endLoop = true;
									break;
								case 2:
									withdraw(Saving[accToModify]);
									endLoop = true;
									break;

								case 3:
									cout << "Compounding Interest at " << Saving[accToModify].getInterestRate() << "%..." << endl;

									Saving[accToModify].payInterest();
									endLoop = true;
									break;

								case 4:
									cout << "Enter the updated first name: ";
									getline(cin, modStringInput);

									Saving[accToModify].setCustomerDetails("firstName", modStringInput);

									cout << "First name updated to " << Saving[accToModify].getCustomerDetails("firstName") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 5:
									cout << "Enter the updated last name: ";
									getline(cin, modStringInput);

									Saving[accToModify].setCustomerDetails("lastName", modStringInput);

									cout << "Last name updated to " << Saving[accToModify].getCustomerDetails("lastName") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 6:
									cout << "Enter the updated address: ";
									getline(cin, modStringInput);

									Saving[accToModify].setCustomerDetails("address", modStringInput);

									cout << "Address updated to " << Saving[accToModify].getCustomerDetails("address") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 7:
									cout << "Enter the updated phone number: ";
									getline(cin, modStringInput);

									Saving[accToModify].setCustomerDetails("phone", modStringInput);

									cout << endl << "Phone number updated to " << Saving[accToModify].getCustomerDetails("phone") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 8:
									cout << "Enter the updated email address: ";
									getline(cin, modStringInput);

									Saving[accToModify].setCustomerDetails("email", modStringInput);

									cout << "Email address updated to " << Saving[accToModify].getCustomerDetails("email") << "." << endl << endl;
									modStringInput = "";
									endLoop = true;
									break;

								case 9:
									cout << "Enter a new ID: ";
									cin >> modIntInput;
									Saving[accToModify].setID(modIntInput);

									cout << "ID updated to " << Saving[accToModify].getID() << "." << endl << endl;
									modIntInput = 0;
									endLoop = true;
									break;

								case 10:
									cout << "Enter account's modified balance: ";
									cin >> modDoubleInput;
									Saving[accToModify].setBalance(modDoubleInput);

									cout << "Balance updated to " << Saving[accToModify].getBalance() << "." << endl << endl;
									modDoubleInput = 0;
									endLoop = true;
									break;

								case 11:
									cout << "Enter a new amount of withdrawals for the account: ";
									cin >> modIntInput;
									Saving[accToModify].setWithdrawals(modIntInput);

									cout << "Withdrawals updated to " << Saving[accToModify].getWithdrawals() << "." << endl << endl;
									modIntInput = 0;
									endLoop = true;
									break;

								case 12:
									cout << "Enter a new amount of deposits for the account: ";
									cin >> modIntInput;
									Saving[accToModify].setDeposits(modIntInput);

									cout << "Deposits updated to " << Saving[accToModify].getDeposits() << "." << endl << endl;
									modIntInput = 0;
									endLoop = true;
									break;

								case 13:
									cout << "Enter a new overdraft limit: ";
									cin >> modIntInput;
									Saving[accToModify].setID(modIntInput);

									cout << "ID updated to " << Saving[accToModify].getID() << "." << endl << endl;
									modIntInput = 0;
									endLoop = true;
									break;

								case 14:
									int modAllChecker;
									cout << "CAUTION: You are now setting ALL elements of the saving account. Would you like to proceed?" << endl <<
										"Enter 0 for NO (Go back) \t Enter 1 for YES (MODIFY ALL ELEMENTS): ";

									cin >> modAllChecker; cin.ignore();

									if (modAllChecker < 0 || modAllChecker > 1)
									{
										cout << "Error MALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
										modAccInput = -1; // Trips the while loop below
									}

									else if (modAllChecker == 0)
									{
										cout << "Returning to previous menu..." << endl << endl;
										modAccInput = -1; // Trips the while loop below
										break;
									}

									else if (modAllChecker == 1)
									{
										getAndModAllInputSaving(Saving[accToModify]);
										cout << endl << "Account Information Modified. Any invalid inputs are set to default. Please double-check the account and modify accordingly if needed." << endl << endl;
										endLoop = true;
										break;
									}

									else
									{
										cout << "FMALL1: Input Error. Please try again. If the problem persists, please contact IT." << endl << endl;
										modAccInput = -1;
									}
									break;

								case 15:

									int deleteAccInput;
									cout << "WARNING: Are you sure you'd like to liquify and delete this account?" << endl <<
										"DELETING ACCOUNTS IS IRREVESIBLE!" << endl;
									cout << "0- No, take me back." << endl <<
										"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

									cout << "Enter input here: ";
									cin >> deleteAccInput;

									if (deleteAccInput < 0 || deleteAccInput > 1)
									{
										cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
										modAccInput = -1; // Trips the while loop below
									}

									else if (deleteAccInput == 0)
									{
										cout << "Returning to previous menu..." << endl << endl;
										modAccInput = -1; // Trips the while loop below
										break;
									}
									else if (deleteAccInput == 1)
									{
										cout << endl << "LAST WARNING: You are about to delete the customer's account. Are you sure you'd like to proceed?" << endl;
										cout << "0- No, take me back." << endl <<
											"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

										cout << "Enter input here: ";
										cin >> deleteAccInput;

										if (deleteAccInput < 0 || deleteAccInput > 1)
										{
											cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (deleteAccInput == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}

										else if (deleteAccInput == 1)
										{
											cout << "Deleting Account..." << endl;
											deleteAccount(Checking, checkingCount, accToModify);
											endLoop = true;
										}

										break;
									}
								}
							} while (modAccInput < 0 || modAccInput > 15);
							break;
						}
					}
					if (endLoop) break;
				}
				break;
			}
			break;

				//Menu Op 2
		case 2:
			//clr terminal here
			cout << "____________________________________________" << endl << endl;
			cout << "\tSearch" << endl << endl;

			int searchByInput;


			cout << "0- Back" << endl;
			cout << "1- Search by last name" << endl;
			cout << "2- Search by ID" << endl;
			cout << "3- Search by phone number" << endl << endl;

			cout << "Please select an option (0-3): ";

			cin >> searchByInput; cin.ignore();

			if (searchByInput == 1) 
			{
				string lNameInput;
				bool found = false;
				do 
				{
					cout << endl << "Enter a last name to search, or enter '0' to exit. ";
					getline(cin, lNameInput);
					cout << endl;

					int accId;
					int accIdInput;

					if (lNameInput == "0") break;

					for (int i = 0; i < accountCounter; i++)
					{
						if (lNameInput == Checking[i].getCustomerDetails("lastName")) 
						{
							accId = Checking[i].getID();
							cout << endl << "Checking Acccount " << accId << ": " << endl;
							Checking[i].printInfo();
							found = true;
						}

						if (lNameInput == Saving[i].getCustomerDetails("lastName"))
						{
							accId = Saving[i].getID();
							cout << endl << "Saving Acccount " << accId << ": " << endl;
							Saving[i].printInfo();
							found = true;
						}
					}

					if (!found)
						cout << "Error SACC1: Account not found.";

					else
					{
						cout << endl << "To modify an account, please enter the ID associated with the account, or press 0 to exit: ";
						cin >> accIdInput; cin.ignore();

						if (accIdInput == 0) 
						{
							cout << "Exiting..." << endl << endl;
							break;
						}

						for (int i = 0; i < accountCounter; i++)
						{
							if (accIdInput == Checking[i].getID()) 
							{
								int modAccInput;

								int modIntInput;
								string modStringInput;
								double modDoubleInput;

								do 
								{
									cout << endl << "Current Account Details:" << endl << endl;
									Checking[i].printInfo();

									printModifyOptionsChecking();

									cin >> modAccInput; cin.ignore();

									switch (modAccInput)
									{
									case 1:
										deposit(Checking[i]);
										break;
									case 2:
										withdraw(Checking[i]);
										break;
									case 3:
										cout << "Enter the updated first name: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("firstName", modStringInput);

										cout << "First name updated to " << Checking[i].getCustomerDetails("firstName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 4:
										cout << "Enter the updated last name: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("lastName", modStringInput);

										cout << "Last name updated to " << Checking[i].getCustomerDetails("lastName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 5:
										cout << "Enter the updated address: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("address", modStringInput);

										cout << "Address updated to " << Checking[i].getCustomerDetails("address") << "." << endl << endl;
										modStringInput = "";

										break;

									case 6:
										cout << "Enter the updated phone number: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("phone", modStringInput);

										cout << endl << "Phone number updated to " << Checking[i].getCustomerDetails("phone") << "." << endl << endl;
										modStringInput = "";
										endLoop = true;
										break;

									case 7:
										cout << "Enter the updated email address: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("email", modStringInput);

										cout << "Email address updated to " << Checking[i].getCustomerDetails("email") << "." << endl << endl;
										modStringInput = "";

										break;

									case 8:
										cout << "Enter a new ID: ";
										cin >> modIntInput;
										Checking[i].setID(modIntInput);

										cout << "ID updated to " << Checking[i].getID() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 9:
										cout << "Enter account's modified balance: ";
										cin >> modDoubleInput;
										Checking[i].setBalance(modDoubleInput);

										cout << "Balance updated to " << Checking[i].getBalance() << "." << endl << endl;
										modDoubleInput = 0;

										break;

									case 10:
										cout << "Enter a new amount of withdrawals for the account: ";
										cin >> modIntInput;
										Checking[i].setWithdrawals(modIntInput);

										cout << "Withdrawals updated to " << Checking[i].getWithdrawals() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 11:
										cout << "Enter a new amount of deposits for the account: ";
										cin >> modIntInput;
										Checking[i].setDeposits(modIntInput);

										cout << "Deposits updated to " << Checking[i].getDeposits() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 12:
										cout << "Enter a new overdraft limit: ";
										cin >> modIntInput;
										Checking[i].setID(modIntInput);

										cout << "ID updated to " << Checking[i].getID() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 13:
										int modAllChecker;
										cout << "CAUTION: You are now setting ALL elements of the checking account. Would you like to proceed?" << endl <<
											"Enter 0 for NO (Go back) \t Enter 1 for YES (MODIFY ALL ELEMENTS): ";

										cin >> modAllChecker; cin.ignore();

										if (modAllChecker < 0 || modAllChecker > 1)
										{
											cout << "Error MALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (modAllChecker == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}

										else if (modAllChecker == 1)
										{
											getAndModAllInputChecking(Checking[i]);
											cout << endl << "Account Information Modified. Any invalid inputs are set to default. Please double-check the account and modify accordingly if needed." << endl << endl;
											break;
										}

										else
										{
											cout << "FMALL1: Input Error. Please try again. If the problem persists, please contact IT." << endl << endl;
											modAccInput = -1;
										}
										break;

									case 14:

										int deleteAccInput;
										cout << "WARNING: Are you sure you'd like to liquify and delete this account?" << endl <<
											"DELETING ACCOUNTS IS IRREVESIBLE!" << endl;
										cout << "0- No, take me back." << endl <<
											"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

										cout << "Enter input here: ";
										cin >> deleteAccInput;

										if (deleteAccInput < 0 || deleteAccInput > 1)
										{
											cout << "Error DALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (deleteAccInput == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}
										else if (deleteAccInput == 1)
										{
											cout << endl << "LAST WARNING: You are about to delete the customer's account. Are you sure you'd like to proceed?" << endl;
											cout << "0- No, take me back." << endl <<
												"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

											cout << "Enter input here: ";
											cin >> deleteAccInput;

											if (deleteAccInput < 0 || deleteAccInput > 1)
											{
												cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
											}

											else if (deleteAccInput == 0)
											{
												cout << "Returning to previous menu..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
												break;
											}

											else if (deleteAccInput == 1)
											{
												cout << "Deleting Account..." << endl;
												deleteAccount(Checking, checkingCount, i);
												endLoop = true;
											}

											break;
										}
									}


								} while (modAccInput < 0 || modAccInput > 14);

							}

							else if (accIdInput == Saving[i].getID())
							{
								int modAccInput;

								int modIntInput;
								string modStringInput;
								double modDoubleInput;

								do
								{
									cout << endl << "Current Account Details:" << endl;
									Saving[i].printInfo();

									printModifyOptionsSaving();

									cin >> modAccInput; cin.ignore();

									switch (modAccInput)
									{
									case 1:
										deposit(Saving[i]);
										break;
									case 2:
										withdraw(Saving[i]);
										break;

									case 3:
										cout << "Compounding Interest at " << Saving[i].getInterestRate() << "%..." << endl;

										Saving[i].payInterest();
										break;

									case 4:
										cout << "Enter the updated first name: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("firstName", modStringInput);

										cout << "First name updated to " << Saving[i].getCustomerDetails("firstName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 5:
										cout << "Enter the updated last name: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("lastName", modStringInput);

										cout << "Last name updated to " << Saving[i].getCustomerDetails("lastName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 6:
										cout << "Enter the updated address: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("address", modStringInput);

										cout << "Address updated to " << Saving[i].getCustomerDetails("address") << "." << endl << endl;
										modStringInput = "";

										break;

									case 7:
										cout << "Enter the updated phone number: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("phone", modStringInput);

										cout << endl << "Phone number updated to " << Saving[i].getCustomerDetails("phone") << "." << endl << endl;
										modStringInput = "";
										endLoop = true;
										break;

									case 8:
										cout << "Enter the updated email address: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("email", modStringInput);

										cout << "Email address updated to " << Saving[i].getCustomerDetails("email") << "." << endl << endl;
										modStringInput = "";

										break;

									case 9:
										cout << "Enter a new ID: ";
										cin >> modIntInput;
										Saving[i].setID(modIntInput);

										cout << "ID updated to " << Saving[i].getID() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 10:
										cout << "Enter account's modified balance: ";
										cin >> modDoubleInput;
										Saving[i].setBalance(modDoubleInput);

										cout << "Balance updated to " << Saving[i].getBalance() << "." << endl << endl;
										modDoubleInput = 0;

										break;

									case 11:
										cout << "Enter a new amount of withdrawals for the account: ";
										cin >> modIntInput;
										Saving[i].setWithdrawals(modIntInput);

										cout << "Withdrawals updated to " << Saving[i].getWithdrawals() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 12:
										cout << "Enter a new amount of deposits for the account: ";
										cin >> modIntInput;
										Saving[i].setDeposits(modIntInput);

										cout << "Deposits updated to " << Saving[i].getDeposits() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 13:
										cout << "Enter a new overdraft limit: ";
										cin >> modIntInput;
										Saving[i].setID(modIntInput);

										cout << "ID updated to " << Saving[i].getID() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 14:
										int modAllChecker;
										cout << "CAUTION: You are now setting ALL elements of the saving account. Would you like to proceed?" << endl <<
											"Enter 0 for NO (Go back) \t Enter 1 for YES (MODIFY ALL ELEMENTS): ";

										cin >> modAllChecker; cin.ignore();

										if (modAllChecker < 0 || modAllChecker > 1)
										{
											cout << "Error MALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (modAllChecker == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}

										else if (modAllChecker == 1)
										{
											getAndModAllInputSaving(Saving[i]);
											cout << endl << "Account Information Modified. Any invalid inputs are set to default. Please double-check the account and modify accordingly if needed." << endl << endl;
											break;
										}

										else
										{
											cout << "FMALL1: Input Error. Please try again. If the problem persists, please contact IT." << endl << endl;
											modAccInput = -1;
										}
										break;

									case 15:

										int deleteAccInput;
										cout << "WARNING: Are you sure you'd like to liquify and delete this account?" << endl <<
											"DELETING ACCOUNTS IS IRREVESIBLE!" << endl;
										cout << "0- No, take me back." << endl <<
											"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

										cout << "Enter input here: ";
										cin >> deleteAccInput;

										if (deleteAccInput < 0 || deleteAccInput > 1)
										{
											cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (deleteAccInput == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}
										else if (deleteAccInput == 1)
										{
											cout << endl << "LAST WARNING: You are about to delete the customer's account. Are you sure you'd like to proceed?" << endl;
											cout << "0- No, take me back." << endl <<
												"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

											cout << "Enter input here: ";
											cin >> deleteAccInput;

											if (deleteAccInput < 0 || deleteAccInput > 1)
											{
												cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
											}

											else if (deleteAccInput == 0)
											{
												cout << "Returning to previous menu..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
												break;
											}

											else if (deleteAccInput == 1)
											{
												cout << "Deleting Account..." << endl;
												deleteAccount(Checking, checkingCount, i);
												endLoop = true;
											}

											break;
										}
									}

								} while (modAccInput < 0 || modAccInput > 14);

							}



						}
					}
				} while (!found);
			}
			else if (searchByInput == 2)
			{
				int idInput;
				bool found = false;
				do
				{
					cout << endl << "Enter an ID to search, or enter '0' to exit. ";
					cin >> idInput; cin.ignore();
					cout << endl;

					int accId;
					int accIdInput;

					if (idInput == 0) break;

					for (int i = 0; i < accountCounter; i++)
					{
						if (idInput == Checking[i].getID())
						{
							accId = Checking[i].getID();
							cout << endl << "Checking Acccount " << accId << ": " << endl;
							Checking[i].printInfo();
							found = true;
						}

						if (idInput == Saving[i].getID())
						{
							accId = Saving[i].getID();
							cout << endl << "Saving Acccount " << accId << ": " << endl;
							Saving[i].printInfo();
							found = true;
						}
					}

					if (!found)
						cout << "Error SACC1: Account not found.";

					else
					{
						cout << endl << "To modify an account, please re-enter the ID associated with the account, or press 0 to exit: ";
						cin >> accIdInput; cin.ignore();

						if (accIdInput == 0)
						{
							cout << "Exiting..." << endl << endl;
							break;
						}

						for (int i = 0; i < accountCounter; i++)
						{
							if (accIdInput == Checking[i].getID())
							{
								int modAccInput;

								int modIntInput;
								string modStringInput;
								double modDoubleInput;

								do
								{
									cout << endl << "Current Account Details:" << endl << endl;
									Checking[i].printInfo();

									printModifyOptionsChecking();

									cin >> modAccInput; cin.ignore();

									switch (modAccInput)
									{
									case 1:
										deposit(Checking[i]);
										break;
									case 2:
										withdraw(Checking[i]);
										break;
									case 3:
										cout << "Enter the updated first name: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("firstName", modStringInput);

										cout << "First name updated to " << Checking[i].getCustomerDetails("firstName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 4:
										cout << "Enter the updated last name: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("lastName", modStringInput);

										cout << "Last name updated to " << Checking[i].getCustomerDetails("lastName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 5:
										cout << "Enter the updated address: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("address", modStringInput);

										cout << "Address updated to " << Checking[i].getCustomerDetails("address") << "." << endl << endl;
										modStringInput = "";

										break;

									case 6:
										cout << "Enter the updated phone number: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("phone", modStringInput);

										cout << endl << "Phone number updated to " << Checking[i].getCustomerDetails("phone") << "." << endl << endl;
										modStringInput = "";
										endLoop = true;
										break;

									case 7:
										cout << "Enter the updated email address: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("email", modStringInput);

										cout << "Email address updated to " << Checking[i].getCustomerDetails("email") << "." << endl << endl;
										modStringInput = "";

										break;

									case 8:
										cout << "Enter a new ID: ";
										cin >> modIntInput;
										Checking[i].setID(modIntInput);

										cout << "ID updated to " << Checking[i].getID() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 9:
										cout << "Enter account's modified balance: ";
										cin >> modDoubleInput;
										Checking[i].setBalance(modDoubleInput);

										cout << "Balance updated to " << Checking[i].getBalance() << "." << endl << endl;
										modDoubleInput = 0;

										break;

									case 10:
										cout << "Enter a new amount of withdrawals for the account: ";
										cin >> modIntInput;
										Checking[i].setWithdrawals(modIntInput);

										cout << "Withdrawals updated to " << Checking[i].getWithdrawals() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 11:
										cout << "Enter a new amount of deposits for the account: ";
										cin >> modIntInput;
										Checking[i].setDeposits(modIntInput);

										cout << "Deposits updated to " << Checking[i].getDeposits() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 12:
										cout << "Enter a new overdraft limit: ";
										cin >> modIntInput;
										Checking[i].setID(modIntInput);

										cout << "ID updated to " << Checking[i].getID() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 13:
										int modAllChecker;
										cout << "CAUTION: You are now setting ALL elements of the checking account. Would you like to proceed?" << endl <<
											"Enter 0 for NO (Go back) \t Enter 1 for YES (MODIFY ALL ELEMENTS): ";

										cin >> modAllChecker; cin.ignore();

										if (modAllChecker < 0 || modAllChecker > 1)
										{
											cout << "Error MALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (modAllChecker == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}

										else if (modAllChecker == 1)
										{
											getAndModAllInputChecking(Checking[i]);
											cout << endl << "Account Information Modified. Any invalid inputs are set to default. Please double-check the account and modify accordingly if needed." << endl << endl;
											break;
										}

										else
										{
											cout << "FMALL1: Input Error. Please try again. If the problem persists, please contact IT." << endl << endl;
											modAccInput = -1;
										}
										break;

									case 14:

										int deleteAccInput;
										cout << "WARNING: Are you sure you'd like to liquify and delete this account?" << endl <<
											"DELETING ACCOUNTS IS IRREVESIBLE!" << endl;
										cout << "0- No, take me back." << endl <<
											"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

										cout << "Enter input here: ";
										cin >> deleteAccInput;

										if (deleteAccInput < 0 || deleteAccInput > 1)
										{
											cout << "Error DALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (deleteAccInput == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}
										else if (deleteAccInput == 1)
										{
											cout << endl << "LAST WARNING: You are about to delete the customer's account. Are you sure you'd like to proceed?" << endl;
											cout << "0- No, take me back." << endl <<
												"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

											cout << "Enter input here: ";
											cin >> deleteAccInput;

											if (deleteAccInput < 0 || deleteAccInput > 1)
											{
												cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
											}

											else if (deleteAccInput == 0)
											{
												cout << "Returning to previous menu..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
												break;
											}

											else if (deleteAccInput == 1)
											{
												cout << "Deleting Account..." << endl;
												deleteAccount(Checking, checkingCount, i);
												endLoop = true;
											}

											break;
										}
									}


								} while (modAccInput < 0 || modAccInput > 14);

							}

							else if (accIdInput == Saving[i].getID())
							{
								int modAccInput;

								int modIntInput;
								string modStringInput;
								double modDoubleInput;

								do
								{
									cout << endl << "Current Account Details:" << endl;
									Saving[i].printInfo();

									printModifyOptionsSaving();

									cin >> modAccInput; cin.ignore();

									switch (modAccInput)
									{
									case 1:
										deposit(Saving[i]);
										break;
									case 2:
										withdraw(Saving[i]);
										break;

									case 3:
										cout << "Compounding Interest at " << Saving[i].getInterestRate() << "%..." << endl;

										Saving[i].payInterest();
										break;

									case 4:
										cout << "Enter the updated first name: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("firstName", modStringInput);

										cout << "First name updated to " << Saving[i].getCustomerDetails("firstName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 5:
										cout << "Enter the updated last name: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("lastName", modStringInput);

										cout << "Last name updated to " << Saving[i].getCustomerDetails("lastName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 6:
										cout << "Enter the updated address: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("address", modStringInput);

										cout << "Address updated to " << Saving[i].getCustomerDetails("address") << "." << endl << endl;
										modStringInput = "";

										break;

									case 7:
										cout << "Enter the updated phone number: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("phone", modStringInput);

										cout << endl << "Phone number updated to " << Saving[i].getCustomerDetails("phone") << "." << endl << endl;
										modStringInput = "";
										endLoop = true;
										break;

									case 8:
										cout << "Enter the updated email address: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("email", modStringInput);

										cout << "Email address updated to " << Saving[i].getCustomerDetails("email") << "." << endl << endl;
										modStringInput = "";

										break;

									case 9:
										cout << "Enter a new ID: ";
										cin >> modIntInput;
										Saving[i].setID(modIntInput);

										cout << "ID updated to " << Saving[i].getID() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 10:
										cout << "Enter account's modified balance: ";
										cin >> modDoubleInput;
										Saving[i].setBalance(modDoubleInput);

										cout << "Balance updated to " << Saving[i].getBalance() << "." << endl << endl;
										modDoubleInput = 0;

										break;

									case 11:
										cout << "Enter a new amount of withdrawals for the account: ";
										cin >> modIntInput;
										Saving[i].setWithdrawals(modIntInput);

										cout << "Withdrawals updated to " << Saving[i].getWithdrawals() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 12:
										cout << "Enter a new amount of deposits for the account: ";
										cin >> modIntInput;
										Saving[i].setDeposits(modIntInput);

										cout << "Deposits updated to " << Saving[i].getDeposits() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 13:
										cout << "Enter a new overdraft limit: ";
										cin >> modIntInput;
										Saving[i].setID(modIntInput);

										cout << "ID updated to " << Saving[i].getID() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 14:
										int modAllChecker;
										cout << "CAUTION: You are now setting ALL elements of the saving account. Would you like to proceed?" << endl <<
											"Enter 0 for NO (Go back) \t Enter 1 for YES (MODIFY ALL ELEMENTS): ";

										cin >> modAllChecker; cin.ignore();

										if (modAllChecker < 0 || modAllChecker > 1)
										{
											cout << "Error MALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (modAllChecker == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}

										else if (modAllChecker == 1)
										{
											getAndModAllInputSaving(Saving[i]);
											cout << endl << "Account Information Modified. Any invalid inputs are set to default. Please double-check the account and modify accordingly if needed." << endl << endl;
											break;
										}

										else
										{
											cout << "FMALL1: Input Error. Please try again. If the problem persists, please contact IT." << endl << endl;
											modAccInput = -1;
										}
										break;

									case 15:

										int deleteAccInput;
										cout << "WARNING: Are you sure you'd like to liquify and delete this account?" << endl <<
											"DELETING ACCOUNTS IS IRREVESIBLE!" << endl;
										cout << "0- No, take me back." << endl <<
											"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

										cout << "Enter input here: ";
										cin >> deleteAccInput;

										if (deleteAccInput < 0 || deleteAccInput > 1)
										{
											cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (deleteAccInput == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}
										else if (deleteAccInput == 1)
										{
											cout << endl << "LAST WARNING: You are about to delete the customer's account. Are you sure you'd like to proceed?" << endl;
											cout << "0- No, take me back." << endl <<
												"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

											cout << "Enter input here: ";
											cin >> deleteAccInput;

											if (deleteAccInput < 0 || deleteAccInput > 1)
											{
												cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
											}

											else if (deleteAccInput == 0)
											{
												cout << "Returning to previous menu..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
												break;
											}

											else if (deleteAccInput == 1)
											{
												cout << "Deleting Account..." << endl;
												deleteAccount(Checking, checkingCount, i);
												endLoop = true;
											}

											break;
										}
									}

								} while (modAccInput < 0 || modAccInput > 14);

							}



						}
					}
				} while (!found);

			}

			else if (searchByInput == 3)
			{
				string phoneInput;
				bool found = false;
				do
				{
					cout << endl << "Enter a phone number to search, or enter '0' to exit. ";
					getline(cin, phoneInput);
					cout << endl;

					int accId;
					int accIdInput;

					if (phoneInput == "0") break;

					for (int i = 0; i < accountCounter; i++)
					{
						if (phoneInput == Checking[i].getCustomerDetails("phone"))
						{
							accId = Checking[i].getID();
							cout << endl << "Checking Acccount " << accId << ": " << endl;
							Checking[i].printInfo();
							found = true;
						}

						if (phoneInput == Saving[i].getCustomerDetails("phone"))
						{
							accId = Saving[i].getID();
							cout << endl << "Saving Acccount " << accId << ": " << endl;
							Saving[i].printInfo();
							found = true;
						}
					}

					if (!found)
						cout << "Error SACC1: Account not found.";

					else
					{
						cout << endl << "To modify an account, please enter the ID associated with the account, or press 0 to exit: ";
						cin >> accIdInput; cin.ignore();

						if (accIdInput == 0)
						{
							cout << "Exiting..." << endl << endl;
							break;
						}

						for (int i = 0; i < accountCounter; i++)
						{
							if (accIdInput == Checking[i].getID())
							{
								int modAccInput;

								int modIntInput;
								string modStringInput;
								double modDoubleInput;

								do
								{
									cout << endl << "Current Account Details:" << endl << endl;
									Checking[i].printInfo();

									printModifyOptionsChecking();

									cin >> modAccInput; cin.ignore();

									switch (modAccInput)
									{
									case 1:
										deposit(Checking[i]);
										break;
									case 2:
										withdraw(Checking[i]);
										break;
									case 3:
										cout << "Enter the updated first name: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("firstName", modStringInput);

										cout << "First name updated to " << Checking[i].getCustomerDetails("firstName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 4:
										cout << "Enter the updated last name: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("lastName", modStringInput);

										cout << "Last name updated to " << Checking[i].getCustomerDetails("lastName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 5:
										cout << "Enter the updated address: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("address", modStringInput);

										cout << "Address updated to " << Checking[i].getCustomerDetails("address") << "." << endl << endl;
										modStringInput = "";

										break;

									case 6:
										cout << "Enter the updated phone number: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("phone", modStringInput);

										cout << endl << "Phone number updated to " << Checking[i].getCustomerDetails("phone") << "." << endl << endl;
										modStringInput = "";
										endLoop = true;
										break;

									case 7:
										cout << "Enter the updated email address: ";
										getline(cin, modStringInput);

										Checking[i].setCustomerDetails("email", modStringInput);

										cout << "Email address updated to " << Checking[i].getCustomerDetails("email") << "." << endl << endl;
										modStringInput = "";

										break;

									case 8:
										cout << "Enter a new ID: ";
										cin >> modIntInput;
										Checking[i].setID(modIntInput);

										cout << "ID updated to " << Checking[i].getID() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 9:
										cout << "Enter account's modified balance: ";
										cin >> modDoubleInput;
										Checking[i].setBalance(modDoubleInput);

										cout << "Balance updated to " << Checking[i].getBalance() << "." << endl << endl;
										modDoubleInput = 0;

										break;

									case 10:
										cout << "Enter a new amount of withdrawals for the account: ";
										cin >> modIntInput;
										Checking[i].setWithdrawals(modIntInput);

										cout << "Withdrawals updated to " << Checking[i].getWithdrawals() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 11:
										cout << "Enter a new amount of deposits for the account: ";
										cin >> modIntInput;
										Checking[i].setDeposits(modIntInput);

										cout << "Deposits updated to " << Checking[i].getDeposits() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 12:
										cout << "Enter a new overdraft limit: ";
										cin >> modIntInput;
										Checking[i].setID(modIntInput);

										cout << "ID updated to " << Checking[i].getID() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 13:
										int modAllChecker;
										cout << "CAUTION: You are now setting ALL elements of the checking account. Would you like to proceed?" << endl <<
											"Enter 0 for NO (Go back) \t Enter 1 for YES (MODIFY ALL ELEMENTS): ";

										cin >> modAllChecker; cin.ignore();

										if (modAllChecker < 0 || modAllChecker > 1)
										{
											cout << "Error MALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (modAllChecker == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}

										else if (modAllChecker == 1)
										{
											getAndModAllInputChecking(Checking[i]);
											cout << endl << "Account Information Modified. Any invalid inputs are set to default. Please double-check the account and modify accordingly if needed." << endl << endl;
											break;
										}

										else
										{
											cout << "FMALL1: Input Error. Please try again. If the problem persists, please contact IT." << endl << endl;
											modAccInput = -1;
										}
										break;

									case 14:

										int deleteAccInput;
										cout << "WARNING: Are you sure you'd like to liquify and delete this account?" << endl <<
											"DELETING ACCOUNTS IS IRREVESIBLE!" << endl;
										cout << "0- No, take me back." << endl <<
											"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

										cout << "Enter input here: ";
										cin >> deleteAccInput;

										if (deleteAccInput < 0 || deleteAccInput > 1)
										{
											cout << "Error DALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (deleteAccInput == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}
										else if (deleteAccInput == 1)
										{
											cout << endl << "LAST WARNING: You are about to delete the customer's account. Are you sure you'd like to proceed?" << endl;
											cout << "0- No, take me back." << endl <<
												"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

											cout << "Enter input here: ";
											cin >> deleteAccInput;

											if (deleteAccInput < 0 || deleteAccInput > 1)
											{
												cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
											}

											else if (deleteAccInput == 0)
											{
												cout << "Returning to previous menu..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
												break;
											}

											else if (deleteAccInput == 1)
											{
												cout << "Deleting Account..." << endl;
												deleteAccount(Checking, checkingCount, i);
												endLoop = true;
											}

											break;
										}
									}


								} while (modAccInput < 0 || modAccInput > 14);

							}

							else if (accIdInput == Saving[i].getID())
							{
								int modAccInput;

								int modIntInput;
								string modStringInput;
								double modDoubleInput;

								do
								{
									cout << endl << "Current Account Details:" << endl;
									Saving[i].printInfo();

									printModifyOptionsSaving();

									cin >> modAccInput; cin.ignore();

									switch (modAccInput)
									{
									case 1:
										deposit(Saving[i]);
										break;
									case 2:
										withdraw(Saving[i]);
										break;

									case 3:
										cout << "Compounding Interest at " << Saving[i].getInterestRate() << "%..." << endl;

										Saving[i].payInterest();
										break;

									case 4:
										cout << "Enter the updated first name: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("firstName", modStringInput);

										cout << "First name updated to " << Saving[i].getCustomerDetails("firstName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 5:
										cout << "Enter the updated last name: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("lastName", modStringInput);

										cout << "Last name updated to " << Saving[i].getCustomerDetails("lastName") << "." << endl << endl;
										modStringInput = "";

										break;

									case 6:
										cout << "Enter the updated address: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("address", modStringInput);

										cout << "Address updated to " << Saving[i].getCustomerDetails("address") << "." << endl << endl;
										modStringInput = "";

										break;

									case 7:
										cout << "Enter the updated phone number: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("phone", modStringInput);

										cout << endl << "Phone number updated to " << Saving[i].getCustomerDetails("phone") << "." << endl << endl;
										modStringInput = "";
										endLoop = true;
										break;

									case 8:
										cout << "Enter the updated email address: ";
										getline(cin, modStringInput);

										Saving[i].setCustomerDetails("email", modStringInput);

										cout << "Email address updated to " << Saving[i].getCustomerDetails("email") << "." << endl << endl;
										modStringInput = "";

										break;

									case 9:
										cout << "Enter a new ID: ";
										cin >> modIntInput;
										Saving[i].setID(modIntInput);

										cout << "ID updated to " << Saving[i].getID() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 10:
										cout << "Enter account's modified balance: ";
										cin >> modDoubleInput;
										Saving[i].setBalance(modDoubleInput);

										cout << "Balance updated to " << Saving[i].getBalance() << "." << endl << endl;
										modDoubleInput = 0;

										break;

									case 11:
										cout << "Enter a new amount of withdrawals for the account: ";
										cin >> modIntInput;
										Saving[i].setWithdrawals(modIntInput);

										cout << "Withdrawals updated to " << Saving[i].getWithdrawals() << "." << endl << endl;
										modIntInput = 0;

										break;

									case 12:
										cout << "Enter a new amount of deposits for the account: ";
										cin >> modIntInput;
										Saving[i].setDeposits(modIntInput);

										cout << "Deposits updated to " << Saving[i].getDeposits() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 13:
										cout << "Enter a new overdraft limit: ";
										cin >> modIntInput;
										Saving[i].setID(modIntInput);

										cout << "ID updated to " << Saving[i].getID() << "." << endl << endl;
										modIntInput = 0;
										break;

									case 14:
										int modAllChecker;
										cout << "CAUTION: You are now setting ALL elements of the saving account. Would you like to proceed?" << endl <<
											"Enter 0 for NO (Go back) \t Enter 1 for YES (MODIFY ALL ELEMENTS): ";

										cin >> modAllChecker; cin.ignore();

										if (modAllChecker < 0 || modAllChecker > 1)
										{
											cout << "Error MALL1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (modAllChecker == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}

										else if (modAllChecker == 1)
										{
											getAndModAllInputSaving(Saving[i]);
											cout << endl << "Account Information Modified. Any invalid inputs are set to default. Please double-check the account and modify accordingly if needed." << endl << endl;
											break;
										}

										else
										{
											cout << "FMALL1: Input Error. Please try again. If the problem persists, please contact IT." << endl << endl;
											modAccInput = -1;
										}
										break;

									case 15:

										int deleteAccInput;
										cout << "WARNING: Are you sure you'd like to liquify and delete this account?" << endl <<
											"DELETING ACCOUNTS IS IRREVESIBLE!" << endl;
										cout << "0- No, take me back." << endl <<
											"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

										cout << "Enter input here: ";
										cin >> deleteAccInput;

										if (deleteAccInput < 0 || deleteAccInput > 1)
										{
											cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
										}

										else if (deleteAccInput == 0)
										{
											cout << "Returning to previous menu..." << endl << endl;
											modAccInput = -1; // Trips the while loop below
											break;
										}
										else if (deleteAccInput == 1)
										{
											cout << endl << "LAST WARNING: You are about to delete the customer's account. Are you sure you'd like to proceed?" << endl;
											cout << "0- No, take me back." << endl <<
												"1- YES, THE CUSTOMER WOULD LIKE TO DELETE THIS ACCOUNT." << endl << endl;

											cout << "Enter input here: ";
											cin >> deleteAccInput;

											if (deleteAccInput < 0 || deleteAccInput > 1)
											{
												cout << "Error DACC1: Invalid input. Please enter 0 or 1. Returning to previous menu for account safety..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
											}

											else if (deleteAccInput == 0)
											{
												cout << "Returning to previous menu..." << endl << endl;
												modAccInput = -1; // Trips the while loop below
												break;
											}

											else if (deleteAccInput == 1)
											{
												cout << "Deleting Account..." << endl;
												deleteAccount(Checking, checkingCount, i);
												endLoop = true;
											}

											break;
										}
									}

								} while (modAccInput < 0 || modAccInput > 14);

							}



						}
					}
				} while (!found);
			}

			break;

			//Menu Op 3
		case 3:
			break;

		default:

			cout << "Error MENI1: Invalid input. Please try again." << endl << endl;
			continue;
			}

		}
	}

