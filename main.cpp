#include "Customer.h"
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "MainFunctions.h"
#include <iostream>
#include <string>
using namespace std;


//system cls to clear previous screens in output, good for good menu
//input validation needs to be reviewed
//need to change the nape of cpp and header files.

int main()
{
	CheckingAccount Checking[10];
	SavingAccount Saving[10];
	int defaultOverdraftLimit = 500;
	bool endLoop = false;

	Checking[0].setAll("Anthony", "Munoz", "2551 mcdon street", "9999999999", "Mario@gmail.com", 1, 2500, 0, 0, 100);
	Checking[1].setAll("Ethan", "Gonzalez Jamison", "4400 Wacdon St", "5865552986", "Ethan@Wakudon.com", 2, 50'000, 5, 2, 10'000);
	Checking[2].setAll("Chopper", "Jamison", "4400 Wacdon St", "5865552986", "Ethan@Wakudon.com", 3, 50'000, 5, 2, 10'000);
	Checking[3].setAll("Ronald", "McDonald", "82 McDonalds Rd", "904-555-8792", "Ronald@coporate.com", 4, 9000, 6000, 10000, 5000);

	Saving[0].setAll("Rock", "Johnson", "2554 Ocean Dr", "(904) 555-1475", "Rock@RockEnterprises.rok", 5, 900'000, 4026, .10, 9867, 10'000);
	Saving[1].setAll("Jock", "Ronson", "2556 Ocean Dr", "(904) 555-1476", "Jock@RonEnterprises.jok", 6, 20000, 864, .08, 687, 9'000);
	Saving[2].setAll("Linoshka", "Smith", "1400 Beach Blvd", "(904) 555-8040", "Lino@gmail.com", 7, 6000, 20, .03, 90, 500);
	Saving[3].setAll("Reza", "Sarraf", "4082 Baymeadows Rd", "(904) 555-1267", "rSarraf1996@ju.edu", 8, 600'000, 0, .20, 9000, 20'000);
	

	int checkingCount = 4;
	int savingCount = 4;
	int accountCounter = checkingCount + savingCount;

	string tempfirstName = "";
	string templastName = "";
	string tempaddress = "";
	string tempphone = "";
	string tempemail = "";
	double amount = 0;
	double amount2 = 0;
	int tempID = 0;
	int tempID2 = 0;
	bool findID = false;
	bool Idcheck = false;


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

		if (menuInput < 0 || menuInput > 4)
		{
			cout << "Error MENI1: Invalid input. Please try again." << endl << endl;
			continue;
		}

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
			cout << "Create a Checking or Saving Account(1 for Checking, 2 for Saving):";
			cin >> menuInput;
			cin.ignore();
			switch (menuInput)
			{
			case 1:

				cout << "Type in firstname:";
				getline(cin, tempfirstName);
				cout << "Type in lastname:";
				getline(cin, templastName);
				cout << "Type in address:";
				getline(cin, tempaddress);
				cout << "Type in phone number:";
				getline(cin, tempphone);
				cout << "Type in email:";
				cin >> tempemail;

				cout << "Congrats Checking Account Succesfully Created!" << endl;

				Checking[checkingCount].setAll(tempfirstName, templastName, tempaddress, tempphone, tempemail, checkingCount+1, 0, 0, 0, 500);

				checkingCount++;
				break;




			case 2:

				cout << "Type in firstname:";
				getline(cin, tempfirstName);
				cout << "Type in lastname:";
				getline(cin, templastName);
				cout << "Type in address:";
				getline(cin, tempaddress);
				cout << "Type in phone number:";
				getline(cin, tempphone);
				cout << "Type in email:";
				cin >> tempemail;

				cout << "Congrats Saving Account Succesfully Created!" << endl;

				Saving[savingCount].setAll(tempfirstName, templastName, tempaddress, tempphone, tempemail, savingCount+1, 0, 0, 0, 500, 0.5);

				savingCount++;
				break;
			}

			break;

		case 4:

			cout << "Checking or Saving Account(1 for Checking, 2 for Saving):";
			cin >> menuInput;
			switch (menuInput)
			{
			case 1:

				cout << "What is your Account ID:";
				cin >> tempID;
				tempID = tempID - 1;


				for (int i = 0; i < 10; i++)
				{
					if (Checking[i].getID() == tempID)
					{
						findID = true;
						break;
					}


				}

				if (findID == true)
				{
					findID = false;
					cout << "Do you want to Transfer to a Checking or saving Account(1 for Checking, 2 for Saving):";
					cin >> menuInput;
					switch (menuInput)
					{
					case 1:




						cout << "Type in The Account ID you want to transfer money into:";
						cin >> tempID2;
						tempID2 = tempID2 - 1;
						for (int i = 0; i < 10; i++)
						{
							if (Checking[i].getID() == tempID2)
							{
								findID = true;
								break;
							}


						}

						if (findID == true)
						{

							cout << "Please select the amount of money you want to transfer:";
							cin >> amount;
							if (amount > 0 && amount <= Checking[tempID].getBalance())
							{

								amount2 = Checking[tempID].getBalance() - amount;
								Checking[tempID].setBalance(amount2);



								amount2 = Checking[tempID2].getBalance() + amount;
								Checking[tempID2].setBalance(amount2);

								cout << "Money has been Transferred Succesfully!" << endl;
								break;

							}



						}
						else
							cout << "Error!" << endl;


						break;

					case 2:


						cout << "Type in The Account ID you want to transfer money into:";
						cin >> tempID2;
						tempID2 = tempID2 - 1;
						for (int i = 0; i < 10; i++)
						{
							if (Checking[i].getID() == tempID2)
							{
								findID = true;
								break;
							}


						}

						if (findID == true)
						{
							cout << "Please select the amount of money you want to transfer:";
							cin >> amount;
							if (amount > 0 && amount <= Checking[tempID].getBalance())
							{

								amount2 = Checking[tempID].getBalance() - amount;
								Checking[tempID].setBalance(amount2);



								amount2 = Saving[tempID2].getBalance() + amount;
								Saving[tempID2].setBalance(amount2);

								cout << "Money has been Transferred Succesfully!" << endl;
								break;

							}


						}
						else
							cout << "Error!" << endl;

					}
					break;

				}
				else
					cout << "Error!" << endl;


				break;




			case 2:

				cout << "What is your Account ID:";
				cin >> tempID;
				tempID = tempID - 1;
				for (int i = 0; i < 10; i++)
				{
					if (Checking[i].getID() == tempID)
					{
						findID = true;
						break;
					}


				}

				if (findID == true)
				{
					findID = false;
					cout << "Do you want to Transfer to a Checking or saving Account(1 for Checking, 2 for Saving):";
					cin >> menuInput;
					switch (menuInput)
					{
					case 1:

						cout << "Type in The Account ID you want to transfer money into:";
						cin >> tempID2;
						tempID2 = tempID2 - 1;
						for (int i = 0; i < 10; i++)
						{
							if (Checking[i].getID() == tempID2)
							{
								findID = true;
								break;
							}


						}

						if (findID == true)
						{
							cout << "Please select the amount of money you want to transfer:";
							cin >> amount;
							if (amount > 0 && amount <= Saving[tempID].getBalance())
							{

								amount2 = Saving[tempID].getBalance() - amount;
								Saving[tempID].setBalance(amount2);



								amount2 = Checking[tempID2].getBalance() + amount;
								Checking[tempID2].setBalance(amount2);

								cout << "Money has been Transferred Succesfully!" << endl;
								break;

							}

						}
						else
							cout << "Error!" << endl;
						break;

					case 2:

						findID = false;

						cout << "Type in The Account ID you want to transfer money into:";
						cin >> tempID2;
						tempID2 = tempID2 - 1;

						for (int i = 0; i < 10; i++)
						{
							if (Checking[i].getID() == tempID2)
							{
								findID = true;
								break;
							}


						}

						if (findID == true)
						{

							cout << "Please select the amount of money you want to transfer:";
							cin >> amount;
							if (amount > 0 && amount <= Saving[tempID].getBalance())
							{

								amount2 = Saving[tempID].getBalance() - amount;
								Saving[tempID].setBalance(amount2);



								amount2 = Saving[tempID2].getBalance() + amount;
								Saving[tempID2].setBalance(amount2);

								cout << "Money has been Transferred Succesfully!" << endl;
								break;

							}


						}
						else
							cout << "Error!" << endl;


						break;
					}

				}
				else
					cout << "Error!" << endl;

				break;






			default:

				cout << "Error MENI1: Invalid input. Please try again." << endl << endl;
				continue;
			}

		}
	}
}
