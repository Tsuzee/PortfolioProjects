// Darren Farr
#include "Entity.h"


// --------------------------------------------------------
// Default Constructor
// --------------------------------------------------------
Entity::Entity() {}

// --------------------------------------------------------
// Deconstructor
// --------------------------------------------------------
Entity::~Entity()
{
	//delete mesh;
}

// --------------------------------------------------------
// Override constructor using the Identity for worldMat with Material and Mesh parameters
// --------------------------------------------------------
Entity::Entity(Mesh* _mesh, Material* _mat, Float3 _pos, Float3 _rot, Float3 _scale)
{
	myHelper = Helpers::getInstance();
	worldMat = myHelper->SetIdentity();
	mesh = _mesh;
	mat = _mat;
	transform.position = _pos;
	transform.rotation = _rot;
	transform.scale = _scale;
	parent = nullptr;
	SetWorldMat();
	posOrig = transform.position;
	rotOrig = transform.rotation;
	scaleOrig = transform.scale;
}

// --------------------------------------------------------
// Override constructor using the Identity for worldMat with a Mesh parameter
// --------------------------------------------------------
Entity::Entity(Mesh* _mesh, Float3 _pos, Float3 _rot, Float3 _scale)
{
	myHelper = Helpers::getInstance();
	worldMat = myHelper->SetIdentity();
	mesh = _mesh;
	transform.position = _pos;
	transform.rotation = _rot;
	transform.scale = _scale;
	parent = nullptr;
	SetWorldMat();
	posOrig = transform.position;
	rotOrig = transform.rotation;
	scaleOrig = transform.scale;
}

// --------------------------------------------------------
// Upadte the entity
// --------------------------------------------------------
void Entity::Update(bool _isLHS)
{
	isLHS = _isLHS;
	SetWorldMat();
}

// --------------------------------------------------------
// Set the Entities parent
// --------------------------------------------------------
void Entity::SetParent(Entity * e)
{
	if (parent != nullptr) {
		for (unsigned i = 0; i < parent->children.size(); i++) {
			if (parent->children[i] == this) {
				parent->children.erase(parent->children.begin() + i);
				break;
			}
		}
		parent = e;
		e->children.push_back(this);
	}
	else {
		parent = e;
		e->children.push_back(this);
	}
}


// --------------------------------------------------------
// Set the world matrix for the entity based on its translation(position), rotation, and/or scale
// --------------------------------------------------------
void Entity::SetWorldMat()
{
	Matrix4X4 mS = myHelper->SetIdentity();
	Matrix4X4 mR = myHelper->SetIdentity();
	Matrix4X4 mT = myHelper->SetIdentity();

	//set Scale
	mS = myHelper->SetScale(mS, transform.scale);

	//set Rotation
	mR = myHelper->SetRotation(mR, transform.rotation);

	// set Translation
	mT = myHelper->SetTranslation(mT, transform.position);

	// set World Matrix
	//worldMat = myHelper->Mult(mR, mS, mT);
	if (isLHS)
	{
		worldMat = myHelper->Mult(mS, mR, mT);	//D3D11
	}
	else
	{
		worldMat = myHelper->Mult(mT, mR, mS);
	}

	if (children.size()>0) {
		for (Entity* e : children) {
			e->SetWorldMat();
		}
	}
}

// --------------------------------------------------------
// Set the position of the entity
// --------------------------------------------------------
void Entity::SetPosition(Float3 newPos)
{
	transform.position = newPos;
}

// --------------------------------------------------------
// Set the rotation of the entity
// --------------------------------------------------------
void Entity::SetRotation(Float3 newRot)
{
	transform.rotation = newRot;
}

// --------------------------------------------------------
// Set the scale of the entity
// --------------------------------------------------------
void Entity::SetScale(Float3 newScale)
{
	transform.scale = newScale;
}

// --------------------------------------------------------
// Return the entities world matrix
// --------------------------------------------------------
Matrix4X4 Entity::GetWorldMat()
{
	return worldMat;
}

// --------------------------------------------------------
// Return the entities position
// --------------------------------------------------------
Float3 Entity::GetPosition()
{
	return transform.position;
}

// --------------------------------------------------------
// Return the entities rotation
// --------------------------------------------------------
Float3 Entity::GetRotation()
{
	return transform.rotation;
}

// --------------------------------------------------------
// Return the entities scale
// --------------------------------------------------------
Float3 Entity::GetScale()
{
	return transform.scale;
}

// --------------------------------------------------------
// Return the entities mesh
// --------------------------------------------------------
Mesh* Entity::GetMesh()
{
	return mesh;
}

// --------------------------------------------------------
// Return the entities material
// --------------------------------------------------------
Material* Entity::GetMat()
{
	return mat;
}

// --------------------------------------------------------
// Return isLHS
// --------------------------------------------------------
bool Entity::GetIsLHS()
{
	return isLHS;
}

// --------------------------------------------------------
// Return the entity back to its original positon, rotation, scale
// --------------------------------------------------------
void Entity::Reset()
{
	transform.position = posOrig;
	transform.rotation = rotOrig;
	transform.scale = scaleOrig;
	Update(isLHS);
}