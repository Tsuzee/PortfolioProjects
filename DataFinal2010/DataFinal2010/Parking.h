//Parking Header

#include "Lots.h"

class Parking
{
public:
	Parking(); //Tracy
	bool isEmpty(int); //Jonathan
	bool isFull(int); //Jonathan
	void welcome(); //Jonathan
	void display(); //Shaun
	bool determineInOut(int); //Tracy
	char determineEntrance(int); //Darren
	int determineLot(); //Darren
	void parkCar(int); //Darren
	void unParkCar(); //Darren
	bool lotsAllFull(); //Tracy
	bool lotsAllEmpty(); //Tracy
	void toMall(); //Tracy
	int randomNumber(); //Darren
	int spotsOccu(int); //Darren
	int mallGoers(); //Darren
	int randCarIn(int); //Darren
	int randCarOut(int); //Darren
	void reset(); //Darren
	void singleHour(int); //Darren

private:
	static const int NUM_LOTS = 8;
	Lots lots[NUM_LOTS];
	int goingToTheMall;
};