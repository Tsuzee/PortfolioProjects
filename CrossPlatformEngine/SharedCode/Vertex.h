#pragma once

#include "SharedMath.h"

//Vertex Sturct to hold Position, UV, Normals, and Tagent data for objects.
struct Vertex
{
	Float3 Position;	// The position of the vertex
	Float2 UV;			// UV location
	Float3 Normal;		// Normal direction
	Float3 Tangent;		// For normal mapping
};

/*
struct Vertex
{
Float3 Position;	// The position of the vertex
Float3 Color;		// Color, temp in for normals
Float2 Uv;			// Uv Coordinate
};

enum VertexElements
{
vertexPosition = 0,
vertexColor,
vertexUv,
vertexElemCount
};
*/