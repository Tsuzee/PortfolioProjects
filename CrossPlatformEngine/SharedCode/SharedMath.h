// Darren Farr
#pragma once

// Declare types
// Based on DirectX 11

// Floats X, Y
typedef struct Float2 {
	float x;
	float y;

	Float2() { x = 0.0f; y = 0.0f; }
	Float2(float x, float y) { this->x = x; this->y = y; }
	Float2 operator+(const Float2& rhs) {
		return Float2(this->x + rhs.x, this->y + rhs.y);
	}
	Float2 operator+(const float& rhs) {
		return Float2(this->x + rhs, this->y + rhs);
	}
	Float2 operator*(const Float2& rhs) {
		return Float2(this->x * rhs.x, this->y * rhs.y);
	}
	Float2 operator*(const float& rhs) {
		return Float2(this->x * rhs, this->y * rhs);
	}

} Float2;

// Floats X, Y, Z
typedef struct Float3 {
	float x;
	float y;
	float z;

	Float3() { x = 0.0f; y = 0.0f; z = 0.0f; }
	Float3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
	Float3 operator+(const Float3& rhs) {
		return Float3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	}
	Float3 operator+(const float& rhs) {
		return Float3(this->x + rhs, this->y + rhs, this->z += rhs);
	}
	Float3 operator-(const Float3& rhs) {
		return Float3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	}
	Float3 operator-(const float& rhs) {
		return Float3(this->x - rhs, this->y - rhs, this->z -= rhs);
	}
	Float3 operator*(const Float3& rhs) {
		return Float3(this->x * rhs.x, this->y * rhs.y, this->z *= rhs.z);
	}
	Float3 operator*(const float& rhs) {
		return Float3(this->x * rhs, this->y * rhs, this->z * rhs);
	}
	Float3 operator/(const Float3& rhs) {
		return Float3(this->x / rhs.x, this->y / rhs.y, this->z /= rhs.z);
	}
	Float3 operator/(const float& rhs) {
		return Float3(this->x / rhs, this->y / rhs, this->z / rhs);
	}
} Float3;

// Floats X, Y, Z, W
typedef struct Float4 {
	float x;
	float y;
	float z;
	float w;

	Float4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }
	Float4(float x, float y, float z, float w) { this->x = x; this->y = y; this->z = z; this->w = w; }
	Float4 operator+(const Float4& rhs) {
		return Float4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
	}
	Float4 operator+(const float& rhs) {
		return Float4(this->x + rhs, this->y + rhs, this->z += rhs, this->w += rhs);
	}
	Float4 operator*(const Float4& rhs) {
		return Float4(this->x * rhs.x, this->y * rhs.y, this->z *= rhs.z, this->w *= rhs.w);
	}
	Float4 operator*(const float& rhs) {
		return Float4(this->x * rhs, this->y * rhs, this->z * rhs, this->w * rhs);
	}

} Float4;


// Based Matrices off of DirectX11


// 3x3 Matrix: 32 bit floating point components
typedef struct Matrix3X3
{
	union
	{
		struct
		{
			float _11, _12, _13;
			float _21, _22, _23;
			float _31, _32, _33;
		};
		float m[3][3];
	};

	Matrix3X3() {}
	Matrix3X3& operator= (const Matrix3X3& Float3x3);
} Matrix3X3;



// 4x4 Matrix: 32 bit floating point components
typedef struct Matrix4X4
{
	union
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};

	Matrix4X4() {}
	Matrix4X4(Float4 a, Float4 b, Float4 c, Float4 d)
	{
		this->_11 = a.x; this->_12 = a.y; this->_13 = a.z; this->_14 = a.w;
		this->_21 = b.x; this->_22 = b.y; this->_23 = b.z; this->_24 = b.w;
		this->_31 = c.x; this->_32 = c.y; this->_33 = c.z; this->_34 = c.w;
		this->_41 = d.x; this->_42 = d.y; this->_43 = d.z; this->_44 = d.w;
	}
} Matrix4X4;

