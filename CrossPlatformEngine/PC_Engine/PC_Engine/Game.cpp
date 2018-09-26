// Darren Farr
#include "Game.h"
#include <time.h>
#include <iostream>

using namespace DirectX;

// --------------------------------------------------------
// Constructor
//
// DXCore (base class) constructor will set up underlying fields.
// DirectX itself, and our window, are not ready yet!
//
// hInstance - the application's OS-level handle (unique ID)
// --------------------------------------------------------
Game::Game(HINSTANCE hInstance)
	: DXCore(
		hInstance,		   // The application's handle
		"DirectX Game",	   // Text for the window's title bar
		1280,			   // Width of the window's client area
		720,			   // Height of the window's client area
		true)			   // Show extra stats (fps) in title bar?
{
	// Initialize fields
	vertexShader = 0;
	pixelShader = 0;
	vertexShaderNormalMap = 0;
	pixelShaderNormalMap = 0;
	pixelShaderBlend = 0;
	pixelShaderNormalMapBlend = 0;

	//SceneBuilder SceneBuild();

	SceneManager SceneManag();
	Renderer Render();
	Cam = new Camera(width, height);

	//Init();

#if defined(DEBUG) || defined(_DEBUG)
	// Do we want a console window?  Probably only in debug mode
	CreateConsoleWindow(500, 120, 32, 120);
	printf("Console window created successfully.  Feel free to printf() here.");
#endif
}

// --------------------------------------------------------
// Destructor - Clean up anything our game has created:
// - Release all DirectX objects created here
// - Delete any objects to prevent memory leaks
// --------------------------------------------------------
Game::~Game()
{
	// Release any (and all!) DirectX objects
	// we've made in the Game class
	//if (vertexBuffer) { vertexBuffer->Release(); }

	// Delete our simple shader objects, which
	// will clean up their own internal DirectX stuff
	delete vertexShader;
	delete pixelShader;
	delete vertexShaderNormalMap;
	delete pixelShaderNormalMap;
	delete skyVS;
	delete skyPS;
	delete pixelShaderBlend;
	delete pixelShaderNormalMapBlend;
	delete particleVS;
	delete particlePS;

	delete player;
	delete Cam;
	delete Pinput;
}

// --------------------------------------------------------
// Called once per program, after DirectX and the window
// are initialized but before the game loop.
// --------------------------------------------------------
void Game::Init()
{
	Cam->SetWidthHeight(width, height);
	Cam->Init();

	LoadShaders();

	Render.SetShaders(vertexShader, pixelShader, vertexShaderNormalMap, pixelShaderNormalMap, skyVS, skyPS,
		pixelShaderBlend, pixelShaderNormalMapBlend, particleVS, particlePS);

	SceneBuild.Init(device, context);
	SceneManag.AddScene(SceneBuild.GetScene(1));

	//Start with scene 1
	SceneNumber = 1;
	setScene();

	

	Render.Init(Cam, device, context, backBufferRTV, swapChain, depthStencilView, width, height);

	player = new Player(SceneBuild.GetPlayerEntity());
	Pinput = new PInput(Cam, player);

	Cam->SetTarget(player->GetPosition());

	// Tell the input assembler stage of the pipeline what kind of
	// geometric primitives (points, lines or triangles) we want to draw.  
	// Essentially: "What kind of shape should the GPU draw with our data?"
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

// --------------------------------------------------------
// Loads shaders from compiled shader object (.cso) files using
// my SimpleShader wrapper for DirectX shader manipulation.
// - SimpleShader provides helpful methods for sending
//   data to individual variables on the GPU
// --------------------------------------------------------
void Game::LoadShaders()
{
	vertexShader = new SimpleVertexShader(device, context);
	if (!vertexShader->LoadShaderFile(L"Debug/VertexShader.cso"))
		vertexShader->LoadShaderFile(L"VertexShader.cso");

	pixelShader = new SimplePixelShader(device, context);
	if (!pixelShader->LoadShaderFile(L"Debug/PixelShader.cso"))
		pixelShader->LoadShaderFile(L"PixelShader.cso");

	vertexShaderNormalMap = new SimpleVertexShader(device, context);
	if (!vertexShaderNormalMap->LoadShaderFile(L"Debug/VertexShaderNormalMap.cso"))
		vertexShaderNormalMap->LoadShaderFile(L"VertexShaderNormalMap.cso");

	pixelShaderNormalMap = new SimplePixelShader(device, context);
	if (!pixelShaderNormalMap->LoadShaderFile(L"Debug/PixelShaderNormalMap.cso"))
		pixelShaderNormalMap->LoadShaderFile(L"PixelShaderNormalMap.cso");

	skyVS = new SimpleVertexShader(device, context);
	if (!skyVS->LoadShaderFile(L"Debug/SkyVS.cso"))
		skyVS->LoadShaderFile(L"SkyVS.cso");

	skyPS = new SimplePixelShader(device, context);
	if (!skyPS->LoadShaderFile(L"Debug/SkyPS.cso"))
		skyPS->LoadShaderFile(L"SkyPS.cso");

	pixelShaderBlend = new SimplePixelShader(device, context);
	if (!pixelShaderBlend->LoadShaderFile(L"Debug/BlendPixelShader.cso"))
		pixelShaderBlend->LoadShaderFile(L"BlendPixelShader.cso");

	pixelShaderNormalMapBlend = new SimplePixelShader(device, context);
	if (!pixelShaderNormalMapBlend->LoadShaderFile(L"Debug/PixelShaderNormalMapBlend.cso"))
		pixelShaderNormalMapBlend->LoadShaderFile(L"PixelShaderNormalMapBlend.cso");

	particleVS = new SimpleVertexShader(device, context);
	if (!particleVS->LoadShaderFile(L"Debug/ParticleVS.cso"))
		particleVS->LoadShaderFile(L"ParticleVS.cso");

	particlePS = new SimplePixelShader(device, context);
	if (!particlePS->LoadShaderFile(L"Debug/ParticlePS.cso"))
		particlePS->LoadShaderFile(L"ParticlePS.cso");
}

void Game::setScene()
{
	//Tell the game which scene it should be rendering, uses 1 based indexing
	Render.SetScene(SceneManag.GetScene(SceneNumber));

}


// --------------------------------------------------------
// Handle resizing DirectX "stuff" to match the new window size.
// For instance, updating our projection matrix's aspect ratio.
// --------------------------------------------------------
void Game::OnResize()
{
	//Cam.Resize(width, height);

	//DXCore::OnResize();
	//Render.Resized(depthStencilView, backBufferRTV, width, height);
}

// --------------------------------------------------------
// Update your game here - user input, move objects, AI, etc.
// --------------------------------------------------------
void Game::Update(float deltaTime, float totalTime)
{
	// Quit if the user event returns true
	if (Pinput->HandleUserEvents(deltaTime)) { Quit(); }


	Scene *currentScene = SceneManag.GetScene(SceneNumber);


	for each (Entity* ent in currentScene->entities)
	{
		ent->Update(true);
	}
	
	player->Update(deltaTime);
	Cam->SetTarget(player->GetPosition());
	Cam->Update();

}

// --------------------------------------------------------
// Clear the screen, redraw everything, present to the user
// --------------------------------------------------------
void Game::Draw(float deltaTime, float totalTime)
{
	Render.Draw(deltaTime, totalTime);
}

#pragma region Mouse Input

// --------------------------------------------------------
// Helper method for mouse clicking.  We get this information
// from the OS-level messages anyway, so these helpers have
// been created to provide basic mouse input if you want it.
// --------------------------------------------------------
void Game::OnMouseDown(WPARAM buttonState, int x, int y)
{
	// Save the previous mouse position, so we have it for the future
	prevMousePos.x = x;
	prevMousePos.y = y;

	// Caputure the mouse so we keep getting mouse move
	// events even if the mouse leaves the window.  we'll be
	// releasing the capture once a mouse button is released
	SetCapture(hWnd);
}

// --------------------------------------------------------
// Helper method for mouse release
// --------------------------------------------------------
void Game::OnMouseUp(WPARAM buttonState, int x, int y)
{
	// We don't care about the tracking the cursor outside
	// the window anymore (we're not dragging if the mouse is up)

	ReleaseCapture();
}

// --------------------------------------------------------
// Helper method for mouse movement.  We only get this message
// if the mouse is currently over the window, or if we're 
// currently capturing the mouse.
// --------------------------------------------------------
void Game::OnMouseMove(WPARAM buttonState, int x, int y)
{
	// Save the previous mouse position, so we have it for the future
	prevMousePos.x = x;
	prevMousePos.y = y;
}

// --------------------------------------------------------
// Helper method for mouse wheel scrolling.  
// WheelDelta may be positive or negative, depending 
// on the direction of the scroll
// --------------------------------------------------------
void Game::OnMouseWheel(float wheelDelta, int x, int y)
{}

#pragma endregion