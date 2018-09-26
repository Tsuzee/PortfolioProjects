// Darren Farr
#include "../Helpers.h"
#include <DirectXMath.h>
#include <cstdio>

using namespace DirectX;

XMFLOAT4X4 Mat4X4ToXMF4X4(Matrix4X4);

bool Helpers::instanceFlag = false;
Helpers* Helpers::single = NULL;
Helpers* Helpers::getInstance()
{
    if (!instanceFlag)
    {
        single = new Helpers();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

// --------------------------------------------------------
// Default Constructor
// --------------------------------------------------------
Helpers::Helpers(){}

// --------------------------------------------------------
// Create a Projection Matrix
// --------------------------------------------------------
Matrix4X4 Helpers::CreateProjectionMat(const float aspectNeg, const float aspect, int bottom, int top, const float depthNear, const float depthFar)
{
	// Create the Projection matrix
	// - This should match the window's aspect ratio, and also update anytime
	//   the window resizes (which is already happening in OnResize() below)
	XMFLOAT4X4 proj;
	XMMATRIX P = XMMatrixPerspectiveFovLH(
		0.25f * 3.1415926535f,		// Field of View Angle
		((float)1280 / (int)720),		// Aspect ratio
		depthNear,						// Near clip plane distance
		depthFar);					// Far clip plane distance
	
	XMStoreFloat4x4(&proj, XMMatrixTranspose(P)); // Transpose for HLSL!

    Float4 a{ proj._11, proj._12, proj._13, proj._14 };
    Float4 b{ proj._21, proj._22, proj._23, proj._24 };
    Float4 c{ proj._31, proj._32, proj._33, proj._34 };
    Float4 d{ proj._41, proj._42, proj._43, proj._44 };

    return Matrix4X4{ a, b, c, d };
}

// --------------------------------------------------------
// Create a View Matrix
// --------------------------------------------------------
Matrix4X4 Helpers::CreateViewMat(Float3 _pos, Float3 _target, Float3 _up)
{
	XMFLOAT4X4 viewXM;

	// Create the View matrix
	// - In an actual game, recreate this matrix every time the camera
	//    moves (potentially every frame)
	// - We're using the LOOK TO function, which takes the position of the
	//    camera and the direction vector along which to look (as well as "up")
	// - Another option is the LOOK AT function, to look towards a specific
	//    point in 3D space
	XMFLOAT4 position = { _pos.x, _pos.y, _pos.z, 1.0f };
	Float3 temp = _target - _pos;
	//XMFLOAT4 direction = XMFLOAT4(temp.x, temp.y, temp.z, 1.0f);
	XMFLOAT4 direction = XMFLOAT4(0, -0.3f, 1, 0);

	XMVECTOR pos = XMLoadFloat4(&position);
	XMVECTOR dir = XMLoadFloat4(&direction);
	XMVECTOR up = XMVectorSet(0, 1, 0, 0);
	XMMATRIX V = XMMatrixLookToLH(
		pos,     // The position of the "camera"
		dir,     // Direction the camera is looking
		up);     // "Up" direction in 3D space (prevents roll)
	XMStoreFloat4x4(&viewXM, XMMatrixTranspose(V)); // Transpose for HLSL!

	Float4 a{ viewXM._11, viewXM._12, viewXM._13, viewXM._14 };
	Float4 b{ viewXM._21, viewXM._22, viewXM._23, viewXM._24 };
	Float4 c{ viewXM._31, viewXM._32, viewXM._33, viewXM._34 };
	Float4 d{ viewXM._41, viewXM._42, viewXM._43, viewXM._44 };

    return Matrix4X4{ a, b, c, d };
}

// --------------------------------------------------------
// Create a Perspective Matrix
// --------------------------------------------------------
Matrix4X4 Helpers::CreatePerspectiveXView(float fov, float aspect, float near, float far, Float3 _pos, Float3 _target, Float3 _up)
{
	XMFLOAT4X4 main;
	Matrix4X4 view = CreateViewMat(_pos, _target, _up);
	XMMATRIX P = XMMatrixIdentity();
	XMFLOAT4X4 persp;
	//XMMATRIX P = XMMatrixPerspectiveFovLH(fov, aspect, near, far);

	P = XMMatrixTranspose(P); // Transpose for HLSL!

	XMFLOAT4X4 view2 = { view._11, view._12, view._13, view._14,
		view._21, view._22, view._23, view._24,
		view._31, view._32, view._33, view._34,
		view._41, view._42, view._43, view._44 };

	XMMATRIX V = XMLoadFloat4x4(&view2);
	XMMATRIX M;

	M = P * V;

	XMStoreFloat4x4(&main, M);

	Float4 a{ main._11, main._12, main._13, main._14 };
	Float4 b{ main._21, main._22, main._23, main._24 };
	Float4 c{ main._31, main._32, main._33, main._34 };
	Float4 d{ main._41, main._42, main._43, main._44 };
	
	return Matrix4X4{ a, b, c, d };
}

// --------------------------------------------------------
// Convert a Matrix4X4 to a XMFLOAT4X4
// --------------------------------------------------------
XMFLOAT4X4 Helpers::Mat4X4ToXMF4X4(Matrix4X4 m)
{
	return XMFLOAT4X4{ m._11, m._12, m._13, m._14,
		m._21, m._22, m._23, m._24,
		m._31, m._32, m._33, m._34,
		m._41, m._42, m._43, m._44 };
}

// --------------------------------------------------------
// Convert a XMFLOAT4X4 to Matrix4X4
// --------------------------------------------------------
Matrix4X4 Helpers::XMF4X4ToMat4X4(XMFLOAT4X4 m)
{
	Float4 a{ m._11, m._12, m._13, m._14 };
	Float4 b{ m._21, m._22, m._23, m._24 };
	Float4 c{ m._31, m._32, m._33, m._34 };
	Float4 d{ m._41, m._42, m._43, m._44 };

	return Matrix4X4{ a, b, c, d };
}

// --------------------------------------------------------
// Convert a Float4 to a XMFLOAT4
// --------------------------------------------------------
XMFLOAT4 Helpers::F4ToXMF4(Float4 f)
{
	return XMFLOAT4(f.x, f.y, f.z, f.w);
}

// --------------------------------------------------------
// Convert a Float3 to a XMFLOAT3
// --------------------------------------------------------
XMFLOAT3 Helpers::F3ToXMF3(Float3 f)
{
	return XMFLOAT3(f.x, f.y, f.z);
}

// --------------------------------------------------------
// Convert a XMFLOAT3 to a Float3
// --------------------------------------------------------
Float3 Helpers::XMF3ToF3(XMFLOAT3 f)
{
	return Float3(f.x, f.y, f.z);
}

// --------------------------------------------------------
// Convert a XMFLOAT4 to a Float4
// --------------------------------------------------------
Float4 Helpers::XMF4ToF4(XMFLOAT4 f)
{
	return Float4(f.x, f.y, f.z, f.w);
}

// --------------------------------------------------------
// Set Matrix to the Identity Matrix.
// --------------------------------------------------------
Matrix4X4 Helpers::SetIdentity()
{
	return Matrix4X4{ {1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f } };
}

// --------------------------------------------------------
// Set the scale of a matrix.
// --------------------------------------------------------
Matrix4X4 Helpers::SetScale(Matrix4X4 mat4, Float3 scale)
{
	XMFLOAT4X4 temp;
	XMMATRIX m;
	m = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(mat4));
	m = DirectX::XMMatrixScaling(scale.x, scale.y, scale.z);
	XMStoreFloat4x4(&temp, m);

	return XMF4X4ToMat4X4(temp);
}

// --------------------------------------------------------
// Set the rotation of a matrix.
// --------------------------------------------------------
Matrix4X4 Helpers::SetRotation(Matrix4X4 mat4, Float3 rotation)
{
	XMFLOAT4X4 temp;
	XMMATRIX m;
	m = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(mat4));
	XMVECTOR _rotT = XMLoadFloat3(&F3ToXMF3(rotation));
	m = DirectX::XMMatrixRotationRollPitchYawFromVector(_rotT);
	XMStoreFloat4x4(&temp, m);

	return XMF4X4ToMat4X4(temp);
}

// --------------------------------------------------------
// Set the translation of a matrix.
// --------------------------------------------------------
Matrix4X4 Helpers::SetTranslation(Matrix4X4 mat4, Float3 position)
{
	XMFLOAT4X4 temp;
	XMMATRIX m;
	m = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(mat4));
	m = DirectX::XMMatrixTranslation(position.x, position.y, position.z);
	XMStoreFloat4x4(&temp, m);

	return XMF4X4ToMat4X4(temp);
}

// --------------------------------------------------------
// Multiply two matrices.
// --------------------------------------------------------
Matrix4X4 Helpers::Mult(Matrix4X4 _m1, Matrix4X4 _m2)
{
	XMFLOAT4X4 temp;
	XMMATRIX m1;
	m1 = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(_m1));
	XMMATRIX m2;
	m2 = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(_m2));
	m2 = DirectX::XMMatrixMultiply(m2, m1);

	//XMStoreFloat4x4(&temp, DirectX::XMMatrixTranspose(m2));
	XMStoreFloat4x4(&temp, m2);

	return XMF4X4ToMat4X4(temp);
}

// --------------------------------------------------------
// Multiply three matrices.
// --------------------------------------------------------
Matrix4X4 Helpers::Mult(Matrix4X4 _m1, Matrix4X4 _m2, Matrix4X4 _m3)
{
	XMFLOAT4X4 temp;
	XMMATRIX m1;
	m1 = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(_m1));
	XMMATRIX m2;
	m2 = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(_m2));
	XMMATRIX m3;
	m3 = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(_m3));

	//m2 = DirectX::XMMatrixMultiply(m2, m1);

	//XMStoreFloat4x4(&temp, DirectX::XMMatrixTranspose(m2));

	XMMATRIX world = m1 * m2 * m3;

	XMStoreFloat4x4(&temp, world);

	return XMF4X4ToMat4X4(temp);
}

// --------------------------------------------------------
// Transpose a matrix.
// --------------------------------------------------------
Matrix4X4 Helpers::Transpose(Matrix4X4 _m)
{
	XMFLOAT4X4 t;
	XMMATRIX m = XMMatrixIdentity();
	m = DirectX::XMLoadFloat4x4(&Mat4X4ToXMF4X4(_m));
	m = XMMatrixTranspose(m);
	XMStoreFloat4x4(&t, m);

	return XMF4X4ToMat4X4(t);
}