// Main

#include "Parking.h"
#include "Display.h"
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
	//declare class
	Parking sim;
	Display dis;

	//declare variables
	int carsPerHourIn = 0;
	int carsPerHourOut = 0;
	int hour = 6;
	bool done = false;
	char choice;
	char choice2 = 'x';

	//clear the screen
	system("cls");

	//Jonathan's Welcome message
	cout << "Welcome to the Mohawk Valley Community College parking simulator!" << endl;
	cout << endl;
	cout << "Would you like to run the simulator?" << "     "<< "Enter y for yes or n for No." << endl;
	cin >> choice;
	if(choice == 'n')
		return 0;
	cout << "If you would like to pick a specific hour between 6am and 5pm to run the the simulation for Enter h. " << endl;
	cout << "Otherwise enter x.\n";
	cin >> choice2; //insert appropriate error check code here

	if (choice2 == 'h')
		{
			cout << "Please enter the hour you wish to test. ";
			cin >> hour;
			sim.singleHour(hour);
			done = true;
			choice2 = 'x';
			dis.displayadmin(sim.spotsOccu(0));
			dis.displayLot1(sim.spotsOccu(1));
			dis.displayLot2(sim.spotsOccu(2));
			dis.displayLot3(sim.spotsOccu(3));
			dis.displayDorm(sim.spotsOccu(4));
			dis.displayopen(sim.spotsOccu(5));
			dis.displaymaint(sim.spotsOccu(6));
			dis.displayoverflow(sim.spotsOccu(7));
			hour = 6;
		}//end if

	while (choice == 'y' && choice2 != 'h')
	{
	while (!done)
	{
		carsPerHourIn = sim.randCarIn(hour);
		carsPerHourOut = sim.randCarOut(hour);


		for (int i = 0; i < carsPerHourIn; i++)
		{
			sim.parkCar(sim.determineLot());
		}//end for

		cout << "Time: " << hour << ":00" << endl;
		dis.displayadmin(sim.spotsOccu(0));
		dis.displayLot1(sim.spotsOccu(1));
		dis.displayLot2(sim.spotsOccu(2));
		dis.displayLot3(sim.spotsOccu(3));
		dis.displayDorm(sim.spotsOccu(4));
		dis.displayopen(sim.spotsOccu(5));
		dis.displaymaint(sim.spotsOccu(6));
		dis.displayoverflow(sim.spotsOccu(7));

		cout << "\nCars that went to the mall: " << sim.mallGoers() << endl;

		for (int j = 0; j < carsPerHourOut; j++)
		{
			sim.unParkCar();
		}//end for

		hour++;
		if (hour == 13)
			hour = 1;
		if (hour == 6)
			done = true;
		Sleep(7000);
		system("cls");

	}//end while

	cout << "Would you like to run the simulator again?" << "     "<< "Enter Y for yes or N for No." << endl;
	cin >> choice; //insert apporpiate error check code here
	done = false;
	sim.reset();
	}//end outside choice while

}//end main