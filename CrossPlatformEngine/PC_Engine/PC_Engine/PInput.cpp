// Darren Farr
#include "../../SharedCode/PInput.h"
#include <DirectXMath.h>

using namespace DirectX;

// --------------------------------------------------------
// Default Constructor
// --------------------------------------------------------
PInput::PInput() {}

// --------------------------------------------------------
// Override Constructor, Camera Parameter
// --------------------------------------------------------
PInput::PInput(Camera* _cam)
{
	Cam = _cam;
}

// --------------------------------------------------------
// Override Constructor, Camera and Player Parameters
// --------------------------------------------------------
PInput::PInput(Camera* _cam, Player* _p)
{
	Cam = _cam;
	MyPlayer = _p;
}

// --------------------------------------------------------
// Deconstructor
// --------------------------------------------------------
PInput::~PInput() {}

// --------------------------------------------------------
// Handle User Input
// --------------------------------------------------------
bool PInput::HandleUserEvents(float deltaTime)
{
		XMVECTOR moveDir = XMVectorZero();
		float moveAmount = 0.7f * deltaTime;

		// Parse Key input
		if (GetAsyncKeyState('W') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.0f, 0.1f });
			MyPlayer->MovePlayer({ 0.0f, 0.0f, 0.1f }, deltaTime);
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.0f, -0.1f });
			MyPlayer->MovePlayer({ 0.0f, 0.0f, -0.1f }, deltaTime);
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			//Cam->MoveCamPos({ -0.1f, 0.0f });
			MyPlayer->MovePlayer({ -0.1f, 0.0f, 0.0f }, deltaTime);
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.1f, 0.0f });
			MyPlayer->MovePlayer({ 0.1f, 0.0f, 0.0f }, deltaTime);
		}
		if (GetAsyncKeyState('R') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.0f, 0.1f, 0.0f });
			MyPlayer->MovePlayer({ 0.0f, 0.1f, 0.0f }, deltaTime);
		}
		if (GetAsyncKeyState('F') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.0f, -0.5f, 0.0f });
			MyPlayer->MovePlayer({ 0.0f, -0.1f, 0.0f }, deltaTime);
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			// Will become Player Jump
		}

		// Test Player Rotations
		if (GetAsyncKeyState('I') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.0f, 0.1f });
			MyPlayer->RotatePlayer({ 0.0f, 0.0f, 0.1f }, deltaTime);
		}
		if (GetAsyncKeyState('K') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.0f, -0.1f });
			MyPlayer->RotatePlayer({ 0.0f, 0.0f, -0.1f }, deltaTime);
		}
		if (GetAsyncKeyState('J') & 0x8000)
		{
			//Cam->MoveCamPos({ -0.1f, 0.0f });
			MyPlayer->RotatePlayer({ 0.1f, 0.0f, 0.0f }, deltaTime);
		}
		if (GetAsyncKeyState('L') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.1f, 0.0f });
			MyPlayer->RotatePlayer({ -0.1f, 0.0f, 0.0f }, deltaTime);
		}
		if (GetAsyncKeyState('U') & 0x8000)
		{
			//Cam->MoveCamPos({ -0.1f, 0.0f });
			MyPlayer->RotatePlayer({ 0.0f, 0.1f, 0.0f }, deltaTime);
		}
		if (GetAsyncKeyState('O') & 0x8000)
		{
			//Cam->MoveCamPos({ 0.1f, 0.0f });
			MyPlayer->RotatePlayer({ 0.0f, -0.1f, 0.0f }, deltaTime);
		}



		// Quit Game
		if (GetAsyncKeyState(VK_ESCAPE)) { return true; }

		return false;
}

// --------------------------------------------------------
// Handle User Input, Unused
// --------------------------------------------------------
bool PInput::HandleUserEvents(double g_act_secs, float deltaTime) { return false; }