// Darren Farr
#pragma once

#include "SharedMath.h"
//#include "../Helpers.h"
#include "../PC_Engine/Helpers.h"

using namespace std;

#define PI 3.14159

// Camera
class Camera
{
public:
	Camera();
	Camera(uint32_t, uint32_t);
	~Camera();

	void Init();

	void SetWidthHeight(uint32_t, uint32_t);
	void Update();
	void SetPosition(Float3);
	void SetEyeTarget(Float3);
	void SetTarget(Float3);
	void MoveCamPos(Float2);
	void MoveCamRot(Float2);
	void MoveCamPos(Float3);
	void MoveCamRot(Float3);

	//void Resize(unsigned int, unsigned int);

	void SetDebugMode(bool);

	Matrix4X4 GetViewMatrix();
	Matrix4X4 GetProjectionMatrix();
	Matrix4X4 GetMainVPM();
	Float4 GetPosition();
	Float3 GetDirection();
	Float3 GetEyeTarget();

private:
	void CreateMatrices(Float3, Float3);

	uint32_t width;
	uint32_t height;

	Matrix4X4 viewMatrix;
	Matrix4X4 projectionMatrix;
	Matrix4X4 mainViewProjMatrix;
	Matrix4X4 viewProjectionMatrix;

	Float3 eyePosition;
	Float3 direction;
	Float3 eyeTarget;
	float rotationX;
	float rotationY;

	Float3 eyeUp;
	Float3 objectRotZYX;
	Float3 objectTrans;
	Float3 target;
	Float3 targetLastPos;

	bool mouseDown;
	bool debugMode;
	bool hasTarget;

	Float3 lastMouse, mouse;

	Helpers *myHelper;
};