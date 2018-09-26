// Darren Farr
// Structs for Lighting
#pragma once

#include "SharedMath.h"

// Global Light
struct GlobalLight
{
	Float4 AmbientColor;
};

// Directional Light
struct DirectionalLight
{
	Float4 DiffuseColor;
	Float3 Direction;
};

// Point Light
struct PointLight
{
	Float4 DiffuseColor;
	Float3 Position;
};

// Spot Light
struct SpotLight
{
	Float4 DiffuseColor;
	Float3 Position;
	float theta;
	Float3 Direction;
	float phi;
};