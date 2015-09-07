//Parking Implementation

#include "Parking.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//Constructor
Parking::Parking()
{
	//srand(time(0));
	lots[0].name = "Admin";
	lots[0].MAX_SPOTS = 40;
	lots[1].name = "Lot 1";
	lots[1].MAX_SPOTS = 500;
	lots[2].name = "Lot 2";
	lots[2].MAX_SPOTS = 600;
	lots[3].name = "Lot 3";
	lots[3].MAX_SPOTS = 200;
	lots[4].name = "Dorm";
	lots[4].MAX_SPOTS = 150;
	lots[5].name = "Open";
	lots[5].MAX_SPOTS = 500;
	lots[6].name = "Maint";
	lots[6].MAX_SPOTS = 200;
	lots[7].name = "Overflow";
	lots[7].MAX_SPOTS = 300;
	for (int i = 0; i < 8; i++)
	{
		lots[i].spotsOccupied = 0;
		lots[i].isEmpty = true;
		lots[i].isFull = false;
	}
	goingToTheMall = 0;
}//end constructor

//reset variables
void Parking::reset()
{
	for (int i = 0; i < 8; i++)
	{
		lots[i].spotsOccupied = 0;
		lots[i].isEmpty = true;
		lots[i].isFull = false;
	}
	goingToTheMall = 0;
}//end reset

//determine if all lots are full
bool Parking::lotsAllFull()
{
	bool full = true;
	for (int i = 0; i < NUM_LOTS; i++)
	{
		if (!lots[i].isFull)
			full = false;
	}
	return full;
}//end lotsallfull

//determine if all lots are empty
bool Parking::lotsAllEmpty()
{
	bool empty = true;
	for (int i = 0; i < NUM_LOTS; i++)
	{
		if (!lots[i].isEmpty)
			empty = false;
	}
	return empty;
}//end lotsallempty

//determine if a lot is empty
bool Parking::isEmpty(int i)
{
	if (lots[i].spotsOccupied == 0)
	{
		cout << "There are no cars in this parking lot." << endl;
		return true;
	}
	else
	{
		cout << "There are cars in this parking lot." << endl;
		return false;
	}
}//end isEmpty

//determine if a lot is full
bool Parking::isFull(int i)
{
	return(lots[i].spotsOccupied == lots[i].MAX_SPOTS);
}//end isFull

//determine how many cars come in to park and how many leave
bool Parking::determineInOut(int multiplier)
{
	bool in = true;
	int odds = 1 + rand() % (100 + multiplier);

	if (odds > 100)
		in = false;

	return in;
}//end determineInOut

//add to the number of cars going to the mall
void Parking::toMall()
{
	goingToTheMall++;
}//end toMall


//generates a random numder between 1 & 100
int Parking::randomNumber()
{
    return (1 + rand() % 100);
}//end randomNumber

//determines the entrance a random car would use
char Parking::determineEntrance(int randNum)
{
    if (randNum > 0 && randNum < 11)
        return 'a';
    else if (randNum > 10 && randNum < 36)
        return 'b';
    else if (randNum > 35 && randNum < 66)
        return 'c';
    else if (randNum > 65 && randNum < 91)
        return 'd';
    else if (randNum > 90 && randNum < 101)
        return 'e';
}//end determineEntrance

//determines the lot used from any given entrance
int Parking::determineLot()
{
    //declare variables
    char entrance;
    int randNum, lot;

    //randomly get an entrance
    entrance = determineEntrance(randomNumber());
    randNum = randomNumber(); //random number for the lot choice

    switch(entrance)
    {
    case 'a':
        //ent shermanA
        lot = 5;
        return lot;
        break;
    case 'b':
        //ent shermanB
        if (randNum > 0 && randNum < 2) //1%
            lot = 0;
        else if (randNum > 3 && randNum < 79)//75%
            lot = 1;
        else if (randNum > 78 && randNum < 99)//20%
            lot = 2;
        else if (randNum > 1 && randNum < 4)//2%
            lot = 3;
        else if (randNum > 98 && randNum < 101)//2%
            lot = 4;
        return lot;
        break;
    case 'c':
        //ent tildenA
        if (randNum > 0 && randNum < 11)//10%
            lot = 4;
        else if (randNum > 10 && randNum < 69)//58%
            lot = 1;
        else if (randNum > 68 && randNum < 99)//30%
            lot = 2;
        else if (randNum > 98 && randNum < 101)//2%
            lot = 3;
        return lot;
        break;
    case 'd':
        //ent tildenB
        if (randNum > 0 && randNum < 21)//20%
            lot = 7;
        else if (randNum > 20 && randNum < 101)//80%
            lot = 6;
        return lot;
        break;
    case 'e':
        //ent armory
        if (randNum > 0 && randNum < 2)//1%
            lot = 4;
        else if (randNum > 4 && randNum < 83)//78%
            lot = 1;
        else if (randNum > 82 && randNum < 101)//18%
            lot = 2;
        else if (randNum > 1 && randNum < 5)//3%
            lot = 3;
        return lot;
        break;
    }//end switch
}//end determineLot 

void Parking::parkCar(int lotNum)
{
	if(lotsAllFull())
	//if(lots[0].spotsOccupied == 40 && lots[1].spotsOccupied == 500 && lots[2].spotsOccupied == 600 && lots[3].spotsOccupied == 200 && lots[4].spotsOccupied == 150 && lots[5].spotsOccupied == 500 && lots[6].spotsOccupied == 200 && lots[7].spotsOccupied == 300 )
	{
		//toMall();
		goingToTheMall++;
		return; //all lots are full, add to mall list
	}//end if

	while (lots[lotNum].isFull)
	{
		if(lotsAllFull())
		//if(lots[0].spotsOccupied == 40 && lots[1].spotsOccupied == 500 && lots[2].spotsOccupied == 600 && lots[3].spotsOccupied == 200 && lots[4].spotsOccupied == 150 && lots[5].spotsOccupied == 500 && lots[6].spotsOccupied == 200 && lots[7].spotsOccupied == 300 )
		{
			//toMall();
			goingToTheMall++;
			return;
		}//end if
		if (lots[6].isFull && lots[7].isFull && lots[0].isFull && lots[1].isFull && lots[2].isFull && lots[3].isFull && lots[4].isFull)
			lotNum = 5;
		else if (lots[6].isFull && lots[7].isFull)
			lotNum = (rand() % 8);
		else if (lotNum == 5)
			lotNum = 1;
		else if (lotNum >= 0 && lotNum < 4)
			lotNum++;
		else if (lotNum == 4)
			lotNum = 0;
		else if (lotNum == 6)
			lotNum = 7;
		else if (lotNum == 7)	
			lotNum = 6;		
	}//end while

	//else
	//{
		lots[lotNum].spotsOccupied++;
		lots[lotNum].isEmpty = false;
		if (lots[lotNum].MAX_SPOTS == lots[lotNum].spotsOccupied)
			lots[lotNum].isFull = true;
	//}//end else
}//end parkCar

//have a car leave a parking lot
void Parking::unParkCar()
{
	int lotNum;

	//if all lots are empty, no cars can leave
	if (lotsAllEmpty())
		return;

	//remove a car from a lot
	lotNum = (rand() % 8);
	while(lots[lotNum].isEmpty)
	{
		lotNum = (rand() % 8);
	}//end while

	if (lots[lotNum].spotsOccupied != 0)
	{
			lots[lotNum].spotsOccupied = (lots[lotNum].spotsOccupied) - 1;
			lots[lotNum].isFull = false;
	}
	//if a lot becomes empty, set its value such
	if (lots[lotNum].spotsOccupied == 0)
		lots[lotNum].isEmpty = true;
}//end unparkcar

int Parking::spotsOccu(int lot)
{
	return lots[lot].spotsOccupied;
}//end spotsOccu

//returns number of cars that went to the mall
int Parking::mallGoers()
{ 
	return goingToTheMall;
}//end mallGoers

//this could be changed to reflect real life parking numbers for a more accurate simulation
int Parking::randCarIn(int hour)//change num to a random number range
{
	double multi;
	double num;
	int carsIn;
	if(hour == 6 || hour == 7)
		num = 180 + (rand() % 40);
		//num = 200;
	else if (hour == 8 || hour == 9)
		num = 460 + (rand() % 80);
		//num = 500;
	else if (hour == 10 || hour == 11 || hour == 12)
		num = 1300 + (rand() % 300);
		//num = 1500;
	else if (hour == 1 || hour == 2 || hour == 3)
		num = 50 + (rand() % 40);
		//num = 70;
	else
		num = 10;

	multi = cos(static_cast<double>(hour));
	carsIn = abs(int(multi * num));
	return carsIn;
}//end randCarIn

int Parking::randCarOut(int hour)
{
	double multi;
	double num;
	int carsOut;
	if(hour == 6 || hour == 7)
		num = 10 + (rand() % 20);
		//num = 20;
	else if (hour == 8 || hour == 9)
		num = 35 + (rand() % 30);
		//num = 50;
	else if (hour == 10 || hour == 11 || hour == 12)
		num = 130 + (rand() % 80);
		//num = 170;
	else if (hour == 1 || hour == 2 || hour == 3)
		num = 450 + (rand() % 100);
		//num = 500;
	else
		num = 1000;

	multi = cos(static_cast<double>(hour));
	carsOut = abs(int(multi * num));
	return carsOut;
}//end randCarOut

//runs the simulation for one specific hour and outputs the data
void Parking::singleHour(int hour)
{
		int carsPerHourIn;
		carsPerHourIn = randCarIn(hour);
			for (int i = 0; i < carsPerHourIn; i++)
		{
			parkCar(determineLot());
		}//end for

		cout << "Time: " << hour << ":00" << endl;
		cout << "\nCars that went to the mall: " << mallGoers() << endl;
}//end singlehour

/*
Lot 0 = Admin, Lot 1 = Lot 1, Lot 2 = Lot 2, Lot 3 = Lot 3, Lot 4 = Dorm
Lot 5 = Open, Lot 6 = Maint, Lot 7 = Overflow
*/