//Darren Farr
#pragma once

#include <vector>
#include "DXCore.h"
#include "SimpleShader.h"
#include <DirectXMath.h>
#include "SceneBuilder.h"
#include "Renderer.h"
#include "../../SharedCode/Camera.h"
#include "../../SharedCode/Player.h"
#include "../../SharedCode/PInput.h"
#include "../../SharedCode/SceneManager.h"

// Handles seting up and running the game
class Game
	: public DXCore
{

public:
	Game(HINSTANCE hInstance);
	~Game();

	// Overridden setup and game loop methods, which
	// will be called automatically
	void Init();
	void OnResize();
	void Update(float deltaTime, float totalTime);
	void Draw(float deltaTime, float totalTime);

	// Overridden mouse input helper methods
	void OnMouseDown(WPARAM buttonState, int x, int y);
	void OnMouseUp(WPARAM buttonState, int x, int y);
	void OnMouseMove(WPARAM buttonState, int x, int y);
	void OnMouseWheel(float wheelDelta, int x, int y);
	
private:
	int SceneNumber;

	// Initialization helper methods - feel free to customize, combine, etc.
	void LoadShaders();
	void setScene();

	// Wrappers for DirectX shaders to provide simplified functionality
	SimpleVertexShader* vertexShader;
	SimplePixelShader* pixelShader;
	SimpleVertexShader* vertexShaderNormalMap;
	SimplePixelShader* pixelShaderNormalMap;
	SimpleVertexShader* skyVS;
	SimplePixelShader* skyPS;

	SimplePixelShader* pixelShaderBlend;
	SimplePixelShader* pixelShaderNormalMapBlend;

	// Particle Shaders
	SimpleVertexShader* particleVS;
	SimplePixelShader* particlePS;


	// Keeps track of the old mouse position.  Useful for 
	// determining how far the mouse moved in a single frame.
	POINT prevMousePos;

	Scene* menueScene;
	Scene* gameScene;
	Scene* endScene;

	SceneBuilder SceneBuild;
	SceneManager SceneManag;
	Renderer Render;
	Camera* Cam;
	PInput* Pinput;
	Player *player;

};

