#include "MainFunctions.h"

void printMainMenu() {

	cout << "____________________________________________" << endl << endl;


	cout << "\tAccount Administrator System" << endl << endl;
	cout << "To manually navigate the menu, please input the corresponding number to the menu choice." << endl << endl;

	cout <<
		"0- Exit" << endl <<
		"1- View and Modify Accounts by List" << endl <<
		"2- View and Modify by Search" << endl <<
		"3- Create an Account" << endl <<
		"4- Transfer Money" << endl << endl <<
		"____________________________________________" << endl << endl <<

		"Enter an option 0-4: ";
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
