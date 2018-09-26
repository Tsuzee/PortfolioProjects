// Darren Farr
#include "Player.h"

//---------------------------------------------------------
// Constructor
//---------------------------------------------------------
Player::Player() {}

//---------------------------------------------------------
// Constructor (PlayerEnt)
//---------------------------------------------------------
Player::Player(Entity* playerEnt) : playerEntity(playerEnt)
{
	//playerCollider = new Collider(playerEntity->GetMesh());
}

//---------------------------------------------------------
// Deconstructor
//---------------------------------------------------------
Player::~Player()
{
	/*if(playerCollider != NULL)
	delete playerCollider;*/
}

//---------------------------------------------------------
// Update player
//---------------------------------------------------------
void Player::Update(float deltaTime)
{
	playerEntity->Update(playerEntity->GetIsLHS());
}


//---------------------------------------------------------
// Move player
//---------------------------------------------------------
void Player::MovePlayer(Float3 mov, float deltaTime)
{
	Move(mov.x, mov.y, mov.z, deltaTime);
}

//---------------------------------------------------------
// Rotate player
//---------------------------------------------------------
void Player::RotatePlayer(Float3 rotAmount, float deltaTime)
{
	Float3 rot = playerEntity->GetRotation();
	//float val = 0.1f * deltaTime;
	float val = 10.f * 0.016f;

	rot.x = rot.x + (rotAmount.x * val);
	rot.y = rot.y + (rotAmount.y * val);
	rot.z = rot.z + (rotAmount.z * val);

	playerEntity->SetRotation(rot);
	Update(deltaTime);
}

//---------------------------------------------------------
// Move
//---------------------------------------------------------
void Player::Move(float x, float y, float z, float deltaTime)
{
	float moveAmount = 10.f * 0.016f;

	Float3 pos = playerEntity->GetPosition();

	pos.x = pos.x + (x * moveAmount);
	pos.y = pos.y + (y * moveAmount);
	pos.z = pos.z + (z * moveAmount);

	playerEntity->SetPosition(pos);
	Update(deltaTime);
}

//---------------------------------------------------------
// Return the player's position
//---------------------------------------------------------
Float3 Player::GetPosition()
{
	return playerEntity->GetPosition();
}

//Collider* Player::GetCollider()
//{
//	return playerCollider;
//}