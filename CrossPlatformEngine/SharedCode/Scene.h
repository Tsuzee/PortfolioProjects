// Darren Farr
#pragma once
#include "Lights.h"
#include "Entity.h"

// Contains vectors of objects that make up a scene. Entities, Lights, Etc.
struct Scene
{
	std::string name;
	std::vector<Entity*> entities;
	std::vector<Entity*> opaque;
	std::vector<Entity*> transparent;
	std::vector<Entity*> opaqueNorm;
	std::vector<Entity*> transparentNorm;
	std::vector<DirectionalLight*> directionalLights;
	std::vector<PointLight*> pointLights;
	std::vector<SpotLight*> spotLights;
	std::vector<GlobalLight*> globalLights;
	Entity* background;
};