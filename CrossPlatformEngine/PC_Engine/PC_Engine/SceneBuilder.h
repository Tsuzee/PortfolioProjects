//Darren Farr
#pragma once
#include "Mesh.h"
#include "Material.h"
#include "../../SharedCode/Lights.h"
#include "../../SharedCode/Scene.h"
#include "../../SharedCode/Vertex.h"

//---------------------------------------------------------
// Scene Manager class
// Contains one or more scenes made up of entities, made of meshes and materials
//---------------------------------------------------------
class SceneBuilder
{
public:
	SceneBuilder();
	~SceneBuilder();

	void Init(ID3D11Device*, ID3D11DeviceContext*);
	void BuildMaterials();
	void BuildLights();
	void BuildMeshes();
	void BuildEntities();
	//void BuildParticles();

	//Entity* CreateEntity(Mesh*, Material*, Float3, Float3, Float3);
	Scene* GetScene(int);
	Entity* GetPlayerEntity();

private:
	void SetupScenes();
	void SortEntityList(Scene*);

	Scene* scene1;
	//Scene* scene2;
	//Scene* scene3;
	//Scene* scene4;

	ID3D11Device* device;
	ID3D11DeviceContext* context;
	//void* device;		//ID3D11Device*
	//void* context;	//ID3D11DeviceContext*

	Mesh* playerMesh;
	Mesh* quadMesh;

	/*Mesh* cubeMesh;
	Mesh* sphereMesh;
	Mesh* asteroidMesh;
	Mesh* skyboxMesh;*/
	
	Material* playerMat;
	Material* grayBoxMat;
	Material* floorMat;
	//Material* backgroundMat;

	Entity* playerEnt;

	// List of temporary Entities for building a test world,
	// did not feel it was necessary to spend time on a level editor or importer.
	Entity* floorEnt1;
	Entity* floorEnt2;
	Entity* floorEnt3;
	Entity* floorEnt4;
	Entity* floorEnt5;
	Entity* floorEnt6;
	Entity* floorEnt7;
	Entity* floorEnt8;
	Entity* floorEnt9;
	Entity* floorEnt10;
	Entity* floorEnt11;
	Entity* floorEnt12;
	Entity* floorEnt13;
	Entity* floorEnt14;
	Entity* floorEnt15;
	Entity* floorEnt16;
	Entity* floorEnt17;
	Entity* floorEnt18;
	Entity* floorEnt19;
	Entity* floorEnt20;
	Entity* floorEnt21;
	Entity* floorEnt22;
	Entity* floorEnt23;
	Entity* floorEnt24;
	Entity* floorEnt25;
	Entity* floorEnt26;
	Entity* floorEnt27;
	Entity* floorEnt28;
	Entity* floorEnt29;
	Entity* floorEnt30;
	Entity* floorEnt31;
	Entity* floorEnt32;
	Entity* floorEnt33;
	Entity* floorEnt34;
	Entity* floorEnt35;
	Entity* floorEnt36;
	Entity* floorEnt37;
	Entity* floorEnt38;
	Entity* floorEnt39;
	Entity* floorEnt40;
	Entity* floorEnt41;

	Entity* bFirstF1;
	Entity* bFirstF2;

	Entity* bSecondF1;
	Entity* bSecondF2;
	Entity* bSecondF3;
	Entity* bSecondF4;
	Entity* bSecondF5;
	Entity* bSecondF6;
	Entity* bSecondF7;
	Entity* bSecondF8;

	Entity* bThirdF1;
	Entity* bThirdF2;
	Entity* bThirdF3;
	Entity* bThirdF4;

	Entity* bFourthF1;
	Entity* bFourthF2;

	Entity* overPass;
	Entity* overPass2;
	Entity* ramp1;
	Entity* ramp2;

	GlobalLight* ambient;
	/*
	directionallight* dirlight;
	directionallight* dirlight2;
	directionallight* dirlight3;
	directionallight* dirlight4;

	pointlight* pointlight;

	spotlight* spotlight;*/


	//Entity* asteroidList[12];

	//Particles Emitter
	//Emitter *emitter;
};