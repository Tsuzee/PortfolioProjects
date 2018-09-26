// Darren Farr
// Scene Manager class
#pragma once
#include "Scene.h"


// Contains one or more scenes made up of entities, made of meshes and materials
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	Scene* GetScene(unsigned int);
	void AddScene(Scene*);
	void RemoveScene(unsigned int);
	unsigned int GetNumOfScenes();

private:
	std::vector<Scene*>Scenes;
	unsigned int numOfScenes;
};