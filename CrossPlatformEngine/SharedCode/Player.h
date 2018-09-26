// Darren Farr
#pragma once

#include "Entity.h"
//#include "Collider.h"

// Player, contains data about player.
class Player
{
public:
	Player();
	Player(Entity* playerEnt);
	~Player();

	//Collider* GetCollider();
	void Update(float);

	// Move these to the char controller
	void MovePlayer(Float3, float);
	void RotatePlayer(Float3, float);

	Float3 GetPosition();

private:
	Entity* playerEntity;
	//Collider* playerCollider;
	bool holdFlag = false;


	// Move these to the char controller
	void Move(float x, float y, float z, float deltaTime);
};

