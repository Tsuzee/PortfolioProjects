//Darren Farr
#include "SceneBuilder.h"

using namespace DirectX;

//---------------------------------------------------------
// Default Constructor
//---------------------------------------------------------
SceneBuilder::SceneBuilder() {}

//---------------------------------------------------------
// Deconstructor
//---------------------------------------------------------
SceneBuilder::~SceneBuilder()
{
	delete playerMesh;
	delete quadMesh;

	delete playerEnt;

	delete scene1;

	delete playerMat;
	delete grayBoxMat;
	delete floorMat;

	delete ambient;

	delete floorEnt1;
	delete floorEnt2;
	delete floorEnt3;
	delete floorEnt4;
	delete floorEnt5;
	delete floorEnt6;
	delete floorEnt7;
	delete floorEnt8;
	delete floorEnt9;
	delete floorEnt10;
	delete floorEnt11;
	delete floorEnt12;
	delete floorEnt13;
	delete floorEnt14;
	delete floorEnt15;
	delete floorEnt16;
	delete floorEnt17;
	delete floorEnt18;
	delete floorEnt19;
	delete floorEnt20;
	delete floorEnt21;
	delete floorEnt22;
	delete floorEnt23;
	delete floorEnt24;
	delete floorEnt25;
	delete floorEnt26;
	delete floorEnt27;
	delete floorEnt28;
	delete floorEnt29;
	delete floorEnt30;
	delete floorEnt31;
	delete floorEnt32;
	delete floorEnt33;
	delete floorEnt34;
	delete floorEnt35;
	delete floorEnt36;
	delete floorEnt37;
	delete floorEnt38;
	delete floorEnt39;
	delete floorEnt40;
	delete floorEnt41;

	delete bFirstF1;
	delete bFirstF2;

	delete bSecondF1;
	delete bSecondF2;
	delete bSecondF3;
	delete bSecondF4;
	delete bSecondF5;
	delete bSecondF6;
	delete bSecondF7;
	delete bSecondF8;

	delete bThirdF1;
	delete bThirdF2;
	delete bThirdF3;
	delete bThirdF4;

	delete bFourthF1;
	delete bFourthF2;

	delete overPass;
	delete overPass2;
	delete ramp1;
	delete ramp2;
}

//---------------------------------------------------------
// Set up a scene
//---------------------------------------------------------
void SceneBuilder::Init(ID3D11Device *_device, ID3D11DeviceContext *_context)
//void SceneBuilder::Init(void *_device, void *_context)
{
	device = _device;
	context = _context;
	BuildMaterials();
	BuildLights();
	BuildMeshes();
	BuildEntities();
	//BuildParticles();
	SetupScenes();
}

//---------------------------------------------------------
// Build Materials Here
//---------------------------------------------------------
void SceneBuilder::BuildMaterials()
{
	//Texture file path
	const wchar_t* path;

	path = L"Assets/textures/player.png";
	playerMat = new Material(device, context, path);

	path = L"Assets/textures/grayBox.png";
	grayBoxMat = new Material(device, context, path);

	path = L"Assets/textures/grayBoxFloor.png";
	floorMat = new Material(device, context, path);

//	path = L"Assets/textures/spaceBackground.dds";
//	backgroundMat = new Material(device, context, path, 0);

//	path = L"Assets/Textures/circleParticle.jpg"; 
//	particelMat = new Material(device, context, path, 1);
}

//---------------------------------------------------------
// Setup lights
//---------------------------------------------------------
void SceneBuilder::BuildLights()
{
	//global ambient light
	ambient = new GlobalLight();
	ambient->AmbientColor = Float4(0.4f, 0.4f, 0.4f, 1.0f);

//	//Directional Lights
//	//-----------------------------------------------------------
//
//	//This light is for a no light place holder to be used if a dir light was used before
//	//and you don't need one in the current scene.
//	dirLight = new DirectionalLight();
//	dirLight->DiffuseColor = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
//	dirLight->Direction = XMVector3(0.0f, 0.0f, 1.0f);

//	//Point Lights
//	//-----------------------------------------------------------
//	pointLight = new PointLight();
//	pointLight->DiffuseColor = XMFLOAT4(0.6f, 1.0f, 1.0f, 1.0f);
//	pointLight->Position = XMVector3(20.0f, 20.0f, 20.0f);
//
//	//Spot Lights
//	//-----------------------------------------------------------
//	spotLight = new SpotLight();
//	spotLight->DiffuseColor = XMFLOAT4(0.8f, 0.3f, 0.0f, 1);
//	spotLight->Direction = XMVector3(0.0f, 0.0f, 1.0f);
//	spotLight->phi = 0.0f;
//	spotLight->Position = XMVector3(0.0f, 15.0f, 0.0f);
//	spotLight->theta = 90.0f;
}

//---------------------------------------------------------
// Build Meshes Here
//---------------------------------------------------------
void SceneBuilder::BuildMeshes()
{
	playerMesh = new Mesh("cube", device, false);
	quadMesh = new Mesh("quad", device, false);
}

//---------------------------------------------------------
// Build Base Entities Here
//---------------------------------------------------------
void SceneBuilder::BuildEntities()
{
	//Entity template (mesh name, material name, position, rotation, scale)

	//menuEnt = new Entity(quadMesh, menuMat, XMVector3(+0.0f, +3.0f, +0.0f), XMVector3(+0.0f, +0.0f, +0.0f), XMVector3(+1.0f, +1.0f, +1.0f));

	//titleEnt = new Entity(quadMesh, titleMat, XMVector3(+0.0f, +5.0f, +0.0f), XMVector3(+0.2f, +0.0f, +0.0f), XMVector3(+13.0f, +1.0f, +1.0f));

	playerEnt = new Entity(playerMesh, playerMat, Float3(+0.0f, +9.5f, -23.5f), Float3(+0.0f, +0.0f, +0.0f), Float3(+0.1f, +0.2f, +0.1f));

	// Starting at the top of the map
	// Strip 1
	floorEnt1 = new Entity(quadMesh, floorMat, Float3(-64.0f, +0.0f, +48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt2 = new Entity(quadMesh, floorMat, Float3(-48.0f, +0.0f, +48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt3 = new Entity(quadMesh, floorMat, Float3(-32.0f, +0.0f, +48.0f), Float3(+1.57f, +0.0f, +0.0f),Float3(+8.0f, +8.0f, +1.0f));
	floorEnt4 = new Entity(quadMesh, floorMat, Float3(-16.0f, +0.0f, +48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt5 = new Entity(quadMesh, floorMat, Float3(+0.0f,  +0.0f, +48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt6 = new Entity(quadMesh, floorMat, Float3(+16.0f, +0.0f, +48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt7 = new Entity(quadMesh, floorMat, Float3(+32.0f, +0.0f, +48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt8 = new Entity(quadMesh, floorMat, Float3(+48.0f, +0.0f, +48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	// Strip 2
	floorEnt9 = new Entity(quadMesh, floorMat, Float3(-64.0f,  +0.0f, +32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt10 = new Entity(quadMesh, floorMat, Float3(-48.0f, +0.0f, +32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt11 = new Entity(quadMesh, floorMat, Float3(-16.0f, +0.0f, +32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt12 = new Entity(quadMesh, floorMat, Float3(+16.0f, +0.0f, +32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt13 = new Entity(quadMesh, floorMat, Float3(+32.0f, +0.0f, +32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt14 = new Entity(quadMesh, floorMat, Float3(+48.0f, +0.0f, +32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	// Strip 3						  
	floorEnt15 = new Entity(quadMesh, floorMat, Float3(-64.0f, +0.0f, +16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt16 = new Entity(quadMesh, floorMat, Float3(-48.0f, +0.0f, +12.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt17 = new Entity(quadMesh, floorMat, Float3(-32.0f, +0.0f, +16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt18 = new Entity(quadMesh, floorMat, Float3(-16.0f, +0.0f, +16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt19 = new Entity(quadMesh, floorMat, Float3(+0.0f,  +0.0f, +16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt20 = new Entity(quadMesh, floorMat, Float3(+16.0f, +0.0f, +16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt21 = new Entity(quadMesh, floorMat, Float3(+48.0f, +0.0f, +16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	// Strip 4						 
	floorEnt22 = new Entity(quadMesh, floorMat, Float3(-64.0f, +0.0f, +0.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt23 = new Entity(quadMesh, floorMat, Float3(-32.0f, +0.0f, +0.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt24 = new Entity(quadMesh, floorMat, Float3(+16.0f, +0.0f, +0.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt25 = new Entity(quadMesh, floorMat, Float3(+32.0f, +0.0f, +0.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt26 = new Entity(quadMesh, floorMat, Float3(+48.0f, +0.0f, +0.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	// Strip 5						
	floorEnt27 = new Entity(quadMesh, floorMat, Float3(+16.0f, +0.0f, -16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt28 = new Entity(quadMesh, floorMat, Float3(+32.0f, +0.0f, -16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt29 = new Entity(quadMesh, floorMat, Float3(+48.0f, +0.0f, -16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	// Strip 6						 
	floorEnt30 = new Entity(quadMesh, floorMat, Float3(-32.0f, +0.0f, -32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt31 = new Entity(quadMesh, floorMat, Float3(+0.0f,  +0.0f, -32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt32 = new Entity(quadMesh, floorMat, Float3(+16.0f, +0.0f, -32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt33 = new Entity(quadMesh, floorMat, Float3(+48.0f, +0.0f, -32.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	// Strip 7						 
	floorEnt34 = new Entity(quadMesh, floorMat, Float3(-32.0f, +0.0f, -48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt35 = new Entity(quadMesh, floorMat, Float3(-16.0f, +0.0f, -48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt36 = new Entity(quadMesh, floorMat, Float3(+0.0f, +0.0f,  -48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt37 = new Entity(quadMesh, floorMat, Float3(+16.0f, +0.0f, -48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt38 = new Entity(quadMesh, floorMat, Float3(+32.0f, +0.0f, -48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt39 = new Entity(quadMesh, floorMat, Float3(+48.0f, +0.0f, -48.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	// Strip 8						
	floorEnt40 = new Entity(quadMesh, floorMat, Float3(-16.0f, +0.0f, -64.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	floorEnt41 = new Entity(quadMesh, floorMat, Float3(+16.0f, +0.0f, -64.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));

	bFirstF1 = new Entity(playerMesh, grayBoxMat, Float3(-48.0f, +0.5f, +24.0f), Float3(+0.0f, +0.0f, +0.0f),  Float3(+16.0f, +1.0f, +8.0f));
	bFirstF2 = new Entity(playerMesh, grayBoxMat, Float3(+0.0f, +0.5f, +0.0f), Float3(+0.0f, +0.0f, +0.0f),    Float3(+16.0f, +1.0f, +16.0f));

	bSecondF1 = new Entity(playerMesh, grayBoxMat, Float3(100.0f, +1.0f, +100.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +2.0f, +16.0f));
	bSecondF2 = new Entity(playerMesh, grayBoxMat, Float3(+32.0f, +1.0f, +16.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +2.0f, +16.0f));
	bSecondF3 = new Entity(playerMesh, grayBoxMat, Float3(-32.0f, +1.0f, -64.0f), Float3(+0.0f, +0.0f, +0.0f),  Float3(+16.0f, +2.0f, +16.0f));
	bSecondF4 = new Entity(playerMesh, grayBoxMat, Float3(-16.0f, +1.0f, 0.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +2.0f, +16.0f));
	bSecondF5 = new Entity(playerMesh, grayBoxMat, Float3(-48.0f, +1.0f, -16.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +2.0f, +16.0f));
	bSecondF6 = new Entity(playerMesh, grayBoxMat, Float3(-48.0f, +1.0f, -32.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +2.0f, +16.0f));
	bSecondF7 = new Entity(playerMesh, grayBoxMat, Float3(-48.0f, +1.0f, -48.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +2.0f, +16.0f));
	bSecondF8 = new Entity(playerMesh, grayBoxMat, Float3(-48.0f, +1.0f, -64.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +2.0f, +16.0f));

	bThirdF1 = new Entity(playerMesh, grayBoxMat, Float3(-32.0f, +1.5f, +32.0f), Float3(+0.0f, +0.0f, +0.0f),   Float3(+16.0f, +3.0f, +16.0f));
	bThirdF2 = new Entity(playerMesh, grayBoxMat, Float3(-48.0f, +1.5f, +0.0f), Float3(+0.0f, +0.0f, +0.0f),  Float3(+16.0f, +3.0f, +16.0f));
	bThirdF3 = new Entity(playerMesh, grayBoxMat, Float3(-16.0f, +1.5f, -32.0f), Float3(+0.0f, +0.0f, +0.0f),   Float3(+16.0f, +3.0f, +16.0f));
	bThirdF4 = new Entity(playerMesh, grayBoxMat, Float3(+0.0f, +1.5f, -64.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +3.0f, +16.0f));

	bFourthF1 = new Entity(playerMesh, grayBoxMat, Float3(+0.0f, +2.0f, +32.0f), Float3(+0.0f, +0.0f, +0.0f),  Float3(+16.0f, +4.0f, +16.0f));
	bFourthF2 = new Entity(playerMesh, grayBoxMat, Float3(+32.0f, +2.0f, -32.0f), Float3(+0.0f, +0.0f, +0.0f), Float3(+16.0f, +4.0f, +16.0f));

	overPass = new Entity(quadMesh, floorMat, Float3(-32.0f, +2.0f, -16.0f), Float3(+1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	overPass2 = new Entity(quadMesh, floorMat, Float3(-32.0f, +1.9f, -16.0f), Float3(-1.57f, +0.0f, +0.0f), Float3(+8.0f, +8.0f, +1.0f));
	ramp1 = new Entity(playerMesh, floorMat, Float3(-16.0f, +1.48f, -16.0f), Float3(+0.0f, +0.0f, -0.065f), Float3(+16.0f, +0.01f, +16.0f));
	ramp2 = new Entity(playerMesh, floorMat, Float3(+.0f, +.5f, -16.0f), Float3(+0.0f, +0.0f, -0.063f), Float3(+16.0f, +0.01f, +16.0f));
}

//---------------------------------------------------------
// Build Particle emitter
//---------------------------------------------------------
//void SceneBuilder::BuildParticles()
//{
//	emitter = new Emitter(
//		200,							// Max particles
//		200,							// Particles per second
//		0.5f,							// Particle lifetime
//		0.25f,							// Start size
//		2.0f,							// End size
//		XMFLOAT4(1, 0.1f, 0.1f, 0.2f),	// Start color
//		XMFLOAT4(1, 1.0f, 1.0f, 0),		// End color
//		XMVector3(10, 10, 0),			// Start velocity
//		XMVector3(0, 0, 0),				// Start position
//		XMVector3(10, 10, 0),			// Start acceleration
//		device,
//		particelMat);
//}

//---------------------------------------------------------
// Setup the built in scenes here
//---------------------------------------------------------
void SceneBuilder::SetupScenes()
{
	//Scene 1
	//--------------------------------------------------------------------------------------------
	scene1 = new Scene();
	scene1->name = "Menu";

	//Entities
	scene1->entities = std::vector<Entity*>();


	////Background
	//scene1->entities.push_back(menuBackgroundEnt);
	//scene1->entities.push_back(titleEnt);

	//Lights
	scene1->globalLights.push_back(ambient);
	//scene1->directionalLights.push_back(dirLight4);


	
	scene1->entities.push_back(playerEnt);
	scene1->entities.push_back(floorEnt1);
	scene1->entities.push_back(floorEnt2);
	scene1->entities.push_back(floorEnt3);
	scene1->entities.push_back(floorEnt4);
	scene1->entities.push_back(floorEnt5);
	scene1->entities.push_back(floorEnt6);
	scene1->entities.push_back(floorEnt7);
	scene1->entities.push_back(floorEnt8);

	scene1->entities.push_back(floorEnt9);
	scene1->entities.push_back(floorEnt10);
	scene1->entities.push_back(floorEnt11);
	scene1->entities.push_back(floorEnt12);
	scene1->entities.push_back(floorEnt13);
	scene1->entities.push_back(floorEnt14);

	scene1->entities.push_back(floorEnt15);
	scene1->entities.push_back(floorEnt16);
	scene1->entities.push_back(floorEnt17);
	scene1->entities.push_back(floorEnt18);
	scene1->entities.push_back(floorEnt19);
	scene1->entities.push_back(floorEnt20);
	scene1->entities.push_back(floorEnt21);

	scene1->entities.push_back(floorEnt22);
	scene1->entities.push_back(floorEnt23);
	scene1->entities.push_back(floorEnt24);
	scene1->entities.push_back(floorEnt25);
	scene1->entities.push_back(floorEnt26);

	scene1->entities.push_back(floorEnt27);
	scene1->entities.push_back(floorEnt28);
	scene1->entities.push_back(floorEnt29);

	scene1->entities.push_back(floorEnt30);
	scene1->entities.push_back(floorEnt31);
	scene1->entities.push_back(floorEnt32);
	scene1->entities.push_back(floorEnt33);

	scene1->entities.push_back(floorEnt34);
	scene1->entities.push_back(floorEnt35);
	scene1->entities.push_back(floorEnt36);
	scene1->entities.push_back(floorEnt37);
	scene1->entities.push_back(floorEnt38);
	scene1->entities.push_back(floorEnt39);

	scene1->entities.push_back(floorEnt40);
	scene1->entities.push_back(floorEnt41);

	scene1->entities.push_back(bFirstF1);
	scene1->entities.push_back(bFirstF2);

	scene1->entities.push_back(bSecondF1);
	scene1->entities.push_back(bSecondF2);
	scene1->entities.push_back(bSecondF3);
	scene1->entities.push_back(bSecondF4);
	scene1->entities.push_back(bSecondF5);
	scene1->entities.push_back(bSecondF6);
	scene1->entities.push_back(bSecondF7);
	scene1->entities.push_back(bSecondF8);

	scene1->entities.push_back(bThirdF1);
	scene1->entities.push_back(bThirdF2);
	//scene1->entities.push_back(bThirdF3);
	scene1->entities.push_back(bThirdF4);

	scene1->entities.push_back(bFourthF1);
	scene1->entities.push_back(bFourthF2);

	scene1->entities.push_back(overPass);
	scene1->entities.push_back(overPass2);
	scene1->entities.push_back(ramp1);
	scene1->entities.push_back(ramp2);

	//End of Scene 1 -----------------------------------------------------------------------------

	//Sort the entities in the scenes
	SortEntityList(scene1);
}


//---------------------------------------------------------
// Create Entities found in the scene
//---------------------------------------------------------
//Entity* SceneBuilder::CreateEntity(Mesh* mesh, Material* mat, Vector3 pos, Vector3 rot, Vector3 scale)
//{
//	Entity* ent = new Entity(mesh, mat, pos, rot, scale);
//
//	return ent;
//}

//---------------------------------------------------------
// Sort the entities lists into opaque or transparent lists, with or without normal maps
//---------------------------------------------------------
void SceneBuilder::SortEntityList(Scene* s)
{

	for (unsigned int i = 0; i < s->entities.size(); i++)
	{
		s->opaque.push_back(s->entities.at(i));
		/*
		if (s->entities.at(i)->GetMat()->UseTransperancy() && s->entities.at(i)->GetMat()->HasNormalMap())
		{
			s->transparentNorm.push_back(s->entities.at(i));
		}
		else if (s->entities.at(i)->GetMat()->UseTransperancy())
		{
			s->transparent.push_back(s->entities.at(i));
		}
		else if (s->entities.at(i)->GetMat()->HasNormalMap())
		{
			s->opaqueNorm.push_back(s->entities.at(i));
		}
		else
		{
			s->opaque.push_back(s->entities.at(i));
		}
		*/
	}
}// End of Sort Entities

//---------------------------------------------------------
// Return the list of entities in the scene
//---------------------------------------------------------
Scene* SceneBuilder::GetScene(int num)
{
	return scene1;

	if (num == 1) { return scene1; }
	/*else if (num == 2) { return scene2; }
	else if (num == 3) { return scene3; }
	else if (num == 4) { return scene4; }*/
	else { return nullptr; }
}

//---------------------------------------------------------
// Return the player Entity
// This needs to go, needs to be requested from the scene itself
//---------------------------------------------------------
Entity* SceneBuilder::GetPlayerEntity()
{
	return playerEnt;
}
