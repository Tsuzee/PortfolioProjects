//Atm.cpp File for Atm.h
//Darren Farr
//Final Project ATM
//MW 10:00

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Atm.h"

using namespace std;

//constructor
Atm::Atm()
{
	pinCount = 0;
	amount = 0;
	checkingBalance = 1000;
	savingBalance = 2000;
	userChoice[arraySize];
	inputAmount[arraySize];
}

//display welcome message
void Atm::welcomeMessage()
{
	for (int i = 0; i < 40; i++)
		cout << "*";
	cout << "\n\n";
	cout << setw(31) <<"Welcome to the C++ ATM\n" << endl;
	for (int i = 0; i < 40; i++)
		cout << "*";
	cout << "\n\n";
}//end welcome

//display initial screen and solicit account card information
bool Atm::gatherCardInfo()
{
	string accountNum;
	cout << "Please enter your 10-digit card number or -1 to exit. ";
	cin >> accountNum;
	if(accountNum == "-1")
		return 0;
	while(accountNum.length() < 10 || accountNum.length() > 10)
	{
		cout << "The card number you entered is invalid. Please try agian. ";
		cin >> accountNum;
	}//end error check while
	return 1;
}//end gatherCard

//solicit pin info
bool Atm::gatherPinInfo()
{
	string accountPin;
	cout << "Please enter your 4-digit PIN number or -1 to exit. ";
	cin >> accountPin;
	if(accountPin == "-1")
		return 0;

	//error check
	while(accountPin.length() < 4 || accountPin.length() > 4)
	{
		cout << "The PIN number you entered is invalid. Please try agian. ";
		cin >> accountPin;
		pinCount++;
		if(pinCount > 2)
		{
			cout << "I'm sorry. You've tried to many pins. Have a nice day." << endl;
			return 0;
		}
	}//end error check while
	return 1;
}//end gatherPin

//display main menu
char Atm::menu()
{
	cout << endl;
	cout << setw(19) << "Main Menu" << endl;
	cout << endl;
	cout << "1.  Withdrawl" << endl;
	cout << "2.  Deposit" << endl;
	cout << "3.  Transfer Funds" << endl;
	cout << "4.  Balance Inquiry" << endl;
	cout << "9.  Help Text" << endl;
	cout << "*.  Exit" << endl;
	cin.clear();	//needed due to cin.getline picking up on the last 
	cin.sync();		//endl and causing an error by not waiting for user input
	cin.getline(userChoice, arraySize);
	choice = errorCheckMenu(userChoice);
	return choice;
}//end main menu

//withdrawl menu
void Atm::withdrawMenu()
{
	system("cls");
	cout << "\nWhich account would you like to withdraw from?" << endl;
	cout << "1. Checking\n2. Savings\n3. Main Menu" << endl;
	cin.getline(userChoice, arraySize);
	choice = errorCheck(userChoice);
	if(choice == '1')
		withdrawChecking();
	if(choice == '2')
		withdrawSaving();
	if(choice == '3')
	{
		system("cls");
		return;
	}
}//end withdrawl menu

//withdraw from checking
void Atm::withdrawChecking()
{
	//solict user input
	cout << "\nHow much would you like to withdraw from your checking account? Enter -1 to cancel withdrawl. ";
	cin >> inputAmount;
	amount = atof(inputAmount);
	amount = errorCheckInput(amount);
	if(amount == -1)
	{
		system("cls");
		return;
	}

	//error check
	while(amount > checkingBalance)
	{
		cout << "I'm sorry, but you do not have that much available to withdraw." << endl;
		cout << "Please enter a smaller amount or enter -1 to cancel withdrawl. ";
		cin >> inputAmount;
		amount = atof(inputAmount);
		amount = errorCheckInput(amount);
		if(amount == -1)
		{
			system("cls");
			return;
		}
	}//end while

	//modify account
	if(amount >= 0)
	{
		amount = roundAmount(amount);
		checkingBalance = roundAmount(checkingBalance - amount);
	}//end if

	//print summary
	system("cls");
	cout << fixed << setprecision(2) << "You withdrew $" << amount << " You're remaining balance is $" << checkingBalance << endl;
}//end withdraw checking

//withdraw from savings
void Atm::withdrawSaving()
{
	//solict user input
	cout << "\nHow much would you like to withdraw from your savings account? Enter -1 to cancel withdrawl. ";
	cin >> inputAmount;
	amount = atof(inputAmount);
	amount = errorCheckInput(amount);
	if(amount == -1)
	{
		system("cls");
		return;
	}

	//error check
	while(amount > savingBalance)
	{
		cout << "I'm sorry, but you do not have that much available to withdraw." << endl;
		cout << "Please enter a smaller amount or enter -1 to cancel withdrawl. ";
		cin >> inputAmount;
		amount = atof(inputAmount);
		amount = errorCheckInput(amount);
		if(amount == -1)
		{
			system("cls");
			return;
		}
	}//end while

	//modify account
	if(amount >= 0)
	{
		amount = roundAmount(amount);
		savingBalance = roundAmount(savingBalance - amount);
	}//end if

	//print summary
	system("cls");
	cout << fixed << setprecision(2) << "You withdrew $" << amount << " You're remaining balance is $" << savingBalance << endl;
}//end withdraw savings

//deposit menu
void Atm::depositMenu()
{
	system("cls");
	cout << "\nWhich account would you like to deposit into?" << endl;
	cout << "1. Checking\n2. Savings\n3. Main Menu" << endl;
	cin.getline(userChoice, arraySize);
	choice = errorCheck(userChoice);
	if(choice == '1')
		depositChecking();
	if(choice == '2')
		depositSaving();
	if(choice == '3')
	{
		system("cls");
		return;
	}
}//end deposit menu

//depsoit into checking
void Atm::depositChecking()
{
	//solict user input
	cout << "\nHow much would you like to deposit your checking account? Enter -1 to cancel deposit. ";
	cin >> inputAmount;
	amount = atof(inputAmount);
	amount = errorCheckInput(amount);
	if(amount == -1)
	{
		system("cls");
		return;
	}

	//error check
	while(amount <= 0)
	{
		cout << "Please enter an amount greater than 0 or enter -1 to cancel deposit. ";
		cin >> inputAmount;
		amount = atof(inputAmount);
		amount = errorCheckInput(amount);
		if(amount == -1)
		{
			system("cls");
			return;
		}
	}//end while

	//modify account
	if(amount >= 0)
	{
		amount = roundAmount(amount);
		checkingBalance = roundAmount(checkingBalance + amount);
	}//end if

	//print summary
	system("cls");
	cout << fixed << setprecision(2) << "You deposited $" << amount << " You're current balance is $" << checkingBalance << endl;
}//end deposit checking

//deposit into savings
void Atm::depositSaving()
{
	//solict user input
	cout << "\nHow much would you like to deposit your savings account?  Enter -1 to cancel deposit. ";
	cin >> inputAmount;
	amount = atof(inputAmount);
	amount = errorCheckInput(amount);
	if(amount == -1)
	{
		system("cls");
		return;
	}

	//error check
	while(amount <= 0)
	{
		cout << "Please enter an amount greater than 0 or enter -1 to cancel deposit. ";
		cin >> inputAmount;
		amount = atof(inputAmount);
		amount = errorCheckInput(amount);
		if(amount == -1)
		{
			system("cls");
			return;
		}
	}//end while

	//modify account
	if(amount >= 0)
	{
		amount = roundAmount(amount);
		savingBalance = roundAmount(savingBalance + amount);
	}//end if

	//print summary
	system("cls");
	cout << fixed << setprecision(2) << "You deposited $" << amount << " You're current balance is $" << savingBalance << endl;
}//end deposit savings

//transfer menu
void Atm::transferMenu()
{
	system("cls");
	cout << "\nHow would you like to transfer your funds?" << endl;
	cout << "1. From Checking into Savings\n2. From Savings into Checking\n3. Main Menu" << endl;
	cin.getline(userChoice, arraySize);
	choice = errorCheck(userChoice);
	if(choice == '1')
		transferToSaving();
	if(choice == '2')
		transferToChecking();
	if(choice == '3')
	{
		system("cls");
		return;
	}
}//end transfer menu

//transfer to checking
void Atm::transferToChecking()
{
	//solict user input
	cout << "\nHow much would you like remove from your savings account and deposit into your checking account? Enter -1 to cancel transfer. ";
	cin >> inputAmount;
	amount = atof(inputAmount);
	amount = errorCheckInput(amount);
	if(amount == -1)
	{
		system("cls");
		return;
	}

	//error check
	while(amount > savingBalance)
	{
		cout << "I'm sorry, but you do not have that much in your savings account." << endl;
		cout << "Please enter a smaller amount or enter -1 to cancel transfer. ";
		cin >> inputAmount;
		amount = atof(inputAmount);
		amount = errorCheckInput(amount);
		if(amount == -1)
		{
			system("cls");
			return;
		}
	}//end while

	//modify accounts
	if(amount >= 0)
	{
		amount = roundAmount(amount);
		savingBalance = roundAmount(savingBalance - amount);
		checkingBalance = roundAmount(checkingBalance + amount);
	}//end if

	//print summary
	system("cls");
	cout << fixed << setprecision(2) << "You transferred $" << amount << " From your savings account." << endl;
	cout << "You're current balances are checking $" << checkingBalance << " and savings $" << savingBalance << endl;
}//end transfer checking

//transfer into savings
void Atm::transferToSaving()
{
	//solict input
	cout << "\nHow much would you like remove from your checking account and deposit into your savings account? Enter -1 to cancel transfer. ";
	cin >> inputAmount;
	amount = atof(inputAmount);
	amount = errorCheckInput(amount);
	if(amount == -1)
	{
		system("cls");
		return;
	}

	//error check
	while(amount > checkingBalance)
	{
		cout << "I'm sorry, but you do not have that much in your checking account." << endl;
		cout << "Please enter a smaller amount or enter -1 to cancel transfer. ";
		cin >> inputAmount;
		amount = atof(inputAmount);
		amount = errorCheckInput(amount);
		if(amount == -1)
		{
			system("cls");
			return;
		}
	}//end while

	//modify accounts
	if(amount >= 0)
	{
		amount = roundAmount(amount);
		savingBalance = roundAmount(savingBalance + amount);
		checkingBalance = roundAmount(checkingBalance - amount);
	}//end if

	//print summary
	system("cls");
	cout << fixed << setprecision(2) << "You transferred $" << amount << " From your checking account." << endl;
	cout << "You're current balances are checking $" << checkingBalance << " and savings $" << savingBalance << endl;
}//end transfer savings

//balance inquiry
void Atm::balanceInquiry()
{
	system("cls");
	cout << "\nYour balances are:" << endl;
	cout << fixed << setprecision(2) << "Checking $" << checkingBalance << endl;
	cout << "Savings $" << savingBalance << endl;
}//end inquiry

//help text
void Atm::helpText()
{
	system("cls");
	cout << setw(33) << "The C++ ATM Help Text\n" << endl;
	cout << "1.  Withdrawl        Allows you to choose which account (Checking or Savings) that you would like to withdraw cash from." << endl;
	cout << "2.  Deposit          Allows you to choose which account (Checking or Savings) that you would like to deposit cash into." << endl;
	cout << "3.  Transfer Funds   Allows you to choose which account (Checking or Savings) that you would like to transfer money from into your other account." << endl;
	cout << "4.  Balance Inquiry  Displays the balances of both your Checking and Savings Accounts." << endl;
	cout << "*.  Exit             Logs out of your accounts and exits the ATM." <<endl << endl << endl;
}//end help

//error check menu input
char Atm::errorCheck(const char choiceArray[])
{
	int count = 0;
	while(choiceArray[0] != '1' && choiceArray[0] != '2' && choiceArray[0] != '3')
	{
		cout << "Please choose option 1, 2, or 3 ";
		cin.getline(userChoice, arraySize);
		count++;
		if(count == 15)	//returns to main menu after too many wrong inputs
			return '3';
	}
	return choiceArray[0];
}//end error check

//error checks menu choice
char Atm::errorCheckMenu(const char choiceArray[])
{
	int count = 0;
	while(choiceArray[0] != '1' && choiceArray[0] != '2' && choiceArray[0] != '3' && choiceArray[0] != '4' && choiceArray[0] != '9' && choiceArray[0] != '*')
	{
		cout << "Please choose option 1, 2, 3, 4, 9, or *. ";
		cin.getline(userChoice, arraySize);
		count++;
		if(count == 10)	//clears screen after too many wrong inputs and pulls up help text
		{
			system("cls");
			helpText();
		}
	}
	return choiceArray[0];
}//end error check

//round incoming amount to keep balances correct to 2 decimals
double Atm::roundAmount(double amount)
{
	amount *=100;
	amount = int(amount);
	amount /= 100;
	return amount;
}//end round

//confirm user input
double Atm::errorCheckInput(double input)
{
	string choice;
	//check for a negative number
	if(input < -1 || (input > -1 && input < 0))
	{
		cout << "Please enter an amount greater then 0 or -1 to cancel. ";
		cin >> inputAmount;
		amount = atof(inputAmount);
		return errorCheckInput(amount);
	}//end if

	//confirm user input
	if(input != -1)
	{
		cout << "\nYou entered $" << fixed << setprecision(2) << input << " Is this correct? (Y or N)";
		cin >> choice;
	}
	else
	{
		cout << "\nYou entered " << setprecision(0) << input << " Is this correct? (Y or N)";
		cin >> choice;
	}//end else

	//error check choice
	while (choice != "Y" && choice != "y" && choice != "N" && choice != "n")
	{
		cout << "Please enter Y or N. ";
		cin >> choice;
	}//end error check loop


	if((choice == "Y" || choice == "y") && input >= -1)
		return input;
	else
	{   //take in new input
		cout << "\nPlease enter an amount.";
		cin >> inputAmount;
		amount = atof(inputAmount);
		return errorCheckInput(amount);
	}//end else
}//end function