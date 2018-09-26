// Darren Farr
#pragma once

#include "Vertex.h"
#include "Transform.h"
#include "SharedMath.h"

//PC
#include "../PC_Engine/PC_Engine/Mesh.h"
#include "../PC_Engine/PC_Engine/Material.h"
#include "../PC_Engine/Helpers.h"

// Entity Class

// An object to hold mesh(s) and local properties
class Entity
{
public:
	Entity();
	~Entity();
	Entity(Mesh*, Material*, Float3, Float3, Float3);
	Entity(Mesh*, Float3, Float3, Float3);

	void Update(bool);

	Matrix4X4 GetWorldMat();
	Float3 GetPosition();
	Float3 GetRotation();
	Float3 GetScale();
	bool GetIsLHS();

	void SetPosition(Float3);
	void SetRotation(Float3);
	void SetScale(Float3);
	void Reset();

	Mesh* GetMesh();
	Material* GetMat();

	Entity* parent;
	std::vector<Entity*> children;

	void SetParent(Entity* e);

private:

	void SetWorldMat();

	Mesh* mesh;
	Material* mat;

	Matrix4X4 worldMat;
	Matrix4X4 localMat;
	Transform transform;

	Float3 posOrig;
	Float3 rotOrig;
	Float3 scaleOrig;

	Helpers* myHelper;

	bool isLHS;	//is left handed system
};