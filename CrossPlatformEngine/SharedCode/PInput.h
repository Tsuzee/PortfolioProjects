// Darren Farr
#pragma once

#include "Camera.h"
//#include Character Controller
#include "Player.h" //temp include


// Abstract Class to handle User Input
class PInput
{
public:
	PInput();
	PInput(Camera*);
	PInput(Camera*, Player*);
	virtual ~PInput();
	virtual bool HandleUserEvents(float);
	virtual bool HandleUserEvents(double, float);

private:
	Camera* Cam;
	Player* MyPlayer;

	Float2 lS;
	Float2 rS;
};