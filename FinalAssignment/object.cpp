#include "object.h"

Object::Object()
{
	mesh_type = null;
	shader_type = phong;
	model = new glm::mat4();
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(1.0, 1.0, 1.0);
	rotation = glm::vec3(0, 0, 0);
}

Object::~Object()
{
	delete model;
}

const Vao& Object::GetVao(GLuint shader_id) const
{
	// Returns vao
	return MeshManager::GetInstance()->GetVao(shader_id, mesh_type);
}

void Object::Animate()
{
	// Animation behaviour
}

glm::mat4 Object::GetModel()
{
	// Returns model
	return *model;
}

ShaderType Object::GetShaderType()
{
	// Returns shader
	return shader_type;
}

void Object::Position(float x, float y, float z)
{
	// Sets xyz positions
	position = glm::vec3(x, y, z);
	UpdateModel();
}

void Object::Scale(float size)
{
	// Set the scale for the xyz
	scale = glm::vec3(size, size, size);
	UpdateModel();
}

void Object::ScaleX(float size)
{
	// Set the scale for the x-axis
	scale.x = size;
	UpdateModel();
}

void Object::ScaleY(float size)
{
	// Set the scale for the y-axis
	scale.y = size;
	UpdateModel();
}

void Object::ScaleZ(float size)
{
	// Set the sclae on the z-axis
	scale.z = size;
	UpdateModel();
}

void Object::RotateX(float angle)
{
	// Set rotation on the x-axis
	rotation.x = angle;
	UpdateModel();
}

void Object::RotateY(float angle)
{
	// Set rotation on the y-axis
	rotation.y = angle;
	UpdateModel();
}

void Object::RotateZ(float angle)
{
	// Set rotation on the z-axis
	rotation.z = angle;
	UpdateModel();
}

void Object::UpdateModel()
{
	// Update the model in the right 
	*model = glm::translate(glm::mat4(), position);
	*model = glm::rotate(*model, glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
	*model = glm::rotate(*model, glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
	*model = glm::rotate(*model, glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));
	*model = glm::scale(*model, scale);
}


