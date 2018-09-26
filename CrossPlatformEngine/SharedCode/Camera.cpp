// Darren Farr
#include "Camera.h"

//---------------------------------------------------------
// Default Constructor
//---------------------------------------------------------
Camera::Camera()
{
	mouseDown = false;
	debugMode = false;

	myHelper = Helpers::getInstance();
}

//---------------------------------------------------------
// Override Constructor
//---------------------------------------------------------
Camera::Camera(uint32_t _width, uint32_t _height)
{
	width = _width;
	height = _height;
	mouseDown = false;
	debugMode = false;
	myHelper = Helpers::getInstance();
}

//---------------------------------------------------------
// Deconstructor
//---------------------------------------------------------
Camera::~Camera() {}

//---------------------------------------------------------
// Set the width and height
//---------------------------------------------------------
void Camera::SetWidthHeight(uint32_t _width, uint32_t _height)
{
	width = _width;
	height = _height;
	hasTarget = false;
}

//---------------------------------------------------------
// Initialize
//---------------------------------------------------------
void Camera::Init()
{
	eyePosition = Float3(0.0f, 10.0f, -25.0f);
	direction = Float3(0, 0, -5);
	eyeTarget = Float3(0.0f, 0.0f, 0.0f);
	rotationX = 0.0f;
	rotationY = 100.0f;
	eyeUp = Float3(0.0f, 1.0f, 0.0f);
	objectRotZYX = { 0.0f, 0.0f, 0.0f };
	objectTrans = { 0.0f, 0.0f, 0.f };

	CreateMatrices(eyePosition, eyeTarget);
}

//---------------------------------------------------------
// Create the base matrices for the camera
//---------------------------------------------------------
void Camera::CreateMatrices(Float3 _eyePos, Float3 eyeTar)
{
	//Setup the camera information
	const float depthNear = 0.1f, depthFar = 100.0f;
	const float aspect = (float)width / (float)height;

	projectionMatrix = myHelper->CreateProjectionMat(-aspect, aspect, -1, 1, depthNear, depthFar);

	viewMatrix = myHelper->CreateViewMat(_eyePos, eyeTarget, eyeUp);

	mainViewProjMatrix
		= myHelper->CreatePerspectiveXView(
			45.0f*PI / 180.0f,
			(float)width / (float)height,
			0.1f,
			1000.0f, _eyePos, eyeTarget, eyeUp);
}

//---------------------------------------------------------
// Camera Update
//---------------------------------------------------------
//void Camera::Update(Float3 pos, float deltaTime)
void Camera::Update()
{
	// if camera has a follow target, update position
	if (hasTarget)
	{
		Float3 move = target - targetLastPos;
		MoveCamPos(move);
		targetLastPos = target;
	}

	CreateMatrices(eyePosition, eyeTarget);
}

//---------------------------------------------------------
// Move the Camera. X - Side/Side, Y - Back/Forth
//---------------------------------------------------------
void Camera::MoveCamPos(Float2 _pos)
{
	float moveAmount = 10.f * 0.016f;

	Float4 pos = GetPosition();
	pos.x = pos.x + (_pos.x * moveAmount);
	pos.z = pos.z + (_pos.y * moveAmount);

	SetPosition({ pos.x, pos.y, pos.z });
}

//---------------------------------------------------------
// Move the Camera. X - Side/Side, Y - Up/Down, Z - Back/Forth
//---------------------------------------------------------
void Camera::MoveCamPos(Float3 _pos)
{
	//float moveAmount = 10.f * 0.016f;
	float moveAmount = 1.0f;

	Float4 pos = GetPosition();
	pos.x = pos.x + (_pos.x * moveAmount);
	pos.y = pos.y + (_pos.y * moveAmount);
	pos.z = pos.z + (_pos.z * moveAmount);
	eyeTarget.x = eyeTarget.x + (_pos.x * moveAmount);
	eyeTarget.y = eyeTarget.y + (_pos.y * moveAmount);
	eyeTarget.z = eyeTarget.z + (_pos.z * moveAmount);

	SetPosition({ pos.x, pos.y, pos.z });
}

//---------------------------------------------------------
// Rotate the Camera
//---------------------------------------------------------
void Camera::MoveCamRot(Float2 rot)
{
	float moveAmount = 0.1f;

	eyeTarget.x = eyeTarget.x + (rot.x * moveAmount);
	eyeTarget.y = eyeTarget.y + (rot.y * moveAmount);
}

//---------------------------------------------------------
// Rotate the Camera
//---------------------------------------------------------
void Camera::MoveCamRot(Float3 rot)
{

}

//---------------------------------------------------------
// Return the view matrix
//---------------------------------------------------------
Matrix4X4 Camera::GetViewMatrix()
{
	return viewMatrix;
}

//---------------------------------------------------------
// Return the projection matrix
//---------------------------------------------------------
Matrix4X4 Camera::GetProjectionMatrix()
{
	return projectionMatrix;
}

//---------------------------------------------------------
// Return the Position
//---------------------------------------------------------
Float4 Camera::GetPosition()
{
	return Float4(eyePosition.x, eyePosition.y, eyePosition.z, 1.0f);
}

//---------------------------------------------------------
// Set the Position
//---------------------------------------------------------
void Camera::SetPosition(Float3 pos)
{
	eyePosition = pos;
	//Update();
}

//---------------------------------------------------------
// Return the Direction
//---------------------------------------------------------
Float3 Camera::GetDirection()
{
	return direction;
}

//---------------------------------------------------------
// Set the Target to follow
//---------------------------------------------------------
void Camera::SetTarget(Float3 targ)
{
	if (!hasTarget) { targetLastPos = targ; }
	hasTarget = true;
	target = targ;
	//Update();
}

//---------------------------------------------------------
// Set the Eye Target
//---------------------------------------------------------
void Camera::SetEyeTarget(Float3 targ)
{
	eyeTarget = targ;
	//Update();
}

//---------------------------------------------------------
// Return the Eye Target
//---------------------------------------------------------
Float3 Camera::GetEyeTarget()
{
	return eyeTarget;
}


//---------------------------------------------------------
// Return the Main View Projection Matrix
//---------------------------------------------------------
Matrix4X4 Camera::GetMainVPM()
{
	return mainViewProjMatrix;
}

//---------------------------------------------------------
// Resize the Screen
//---------------------------------------------------------
//void Camera::Resize(unsigned int width, unsigned int height)
//{
//
//	// Update our projection matrix since the window size changed
//	XMMATRIX P = XMMatrixPerspectiveFovLH(
//		0.25f * 3.1415926535f,	// Field of View Angle
//		(float)width / height,	// Aspect ratio
//		0.1f,				  	// Near clip plane distance
//		100.0f);			  	// Far clip plane distance
//	XMStoreFloat4x4(&projectionMatrix, XMMatrixTranspose(P)); // Transpose for HLSL!
//}

//---------------------------------------------------------
// Toggle Camera debug mode
//---------------------------------------------------------
void Camera::SetDebugMode(bool mode)
{
	debugMode = mode;
}