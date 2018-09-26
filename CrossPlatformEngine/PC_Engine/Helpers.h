#pragma once
#include <DirectXMath.h>
#include "../SharedCode/SharedMath.h"

using namespace DirectX;

//Virtual Helper Functions

class Helpers {

	static bool instanceFlag;
	static Helpers *single;
	Helpers();

public:
	static Helpers* getInstance();

	~Helpers()
	{
		instanceFlag = false;
	}

	Matrix4X4 CreateProjectionMat(const float, const float, int, int, const float, const float);
	Matrix4X4 CreateViewMat(Float3, Float3, Float3);
	Matrix4X4 CreatePerspectiveXView( float,  float,  float,  float, Float3, Float3, Float3);
	
	//Convert from one tpye to another

	XMFLOAT4X4 Mat4X4ToXMF4X4(Matrix4X4);
	Matrix4X4 XMF4X4ToMat4X4(XMFLOAT4X4);
	XMFLOAT4 F4ToXMF4(Float4);
	XMFLOAT3 F3ToXMF3(Float3);
	Float3 XMF3ToF3(XMFLOAT3);
	Float4 XMF4ToF4(XMFLOAT4);

	//Matrix Math Functions

	Matrix4X4 SetIdentity();
	Matrix4X4 SetScale(Matrix4X4, Float3);
	Matrix4X4 SetRotation(Matrix4X4, Float3);
	Matrix4X4 SetTranslation(Matrix4X4, Float3);
	Matrix4X4 Mult(Matrix4X4, Matrix4X4);
	Matrix4X4 Mult(Matrix4X4, Matrix4X4, Matrix4X4);
	Matrix4X4 Transpose(Matrix4X4);

};