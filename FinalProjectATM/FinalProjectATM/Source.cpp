//Darren Farr
//Final Project ATM
//MW 10:00

#include <iostream>
#include "stdlib.h"
#include "Atm.h"

using namespace std;

int main()
{
	system("cls");		//clear screen


	//declare variables
	char choice;
	
	Atm myAtm;		//declare an instance of class atm
	myAtm.welcomeMessage();		//output welcome
	if(myAtm.gatherCardInfo() == 0)		//gather card number
		return 0;
	if(myAtm.gatherPinInfo() == 0)		//gather pin number
		return 0;
	choice = myAtm.menu();

	//select from menu
	while(choice != '*')
	{
		switch (choice)
		{
		case '1':
			myAtm.withdrawMenu();
			break;
		case '2':
			myAtm.depositMenu();
			break;
		case '3':
			myAtm.transferMenu();
			break;
		case '4':
			myAtm.balanceInquiry();
			break;
		case '9':
			myAtm.helpText();
			break;
		}//end switch
		choice = myAtm.menu();
	}//end while
}//end main