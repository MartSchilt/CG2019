#include "object.h"

Object::Object()
{
	// Initialize vectors
	model = new glm::mat4();
	position = glm::vec3(0, 0, 0);
	scale = glm::vec3(1.0, 1.0, 1.0);
	rotation = glm::vec3(0, 0, 0);
	
	// These are placeholders so implementation is easier
	texture_path = "Textures/Yellobrk";
	mesh_type = cube;
	shader_type = standard;
}

Object::~Object()
{
	delete model;
}

const Vao& Object::GetVao(GLuint shader_id) const
{
	// Returns the vao
	return MeshManager::GetInstance()->GetVao(shader_id, mesh_type);
}

// Safeholder in case if an object doesn't implement the Animate function
void Object::Animate()
{ }

glm::mat4 Object::GetModel()
{
	// Returns the model
	return *model;
}

ShaderType Object::GetShaderType()
{
	// Returns the shader
	return shader_type;
}

void Object::Position(float x, float y, float z)
{
	// Sets x, y and z location
	position = glm::vec3(x, y, z);
	UpdateModel();
}

void Object::Scale(float scale_size)
{
	// Set the scale for the x- y- and z-axis as a whole
	scale = glm::vec3(scale_size, scale_size, scale_size);
	UpdateModel();
}

void Object::Scale(float scale_x, float scale_y, float scale_z = 1)
{
	// Set the scale for the x- y- and z-axis separately
	scale = glm::vec3(scale_x, scale_y, scale_z);
	UpdateModel();
}

void Object::Rotate(float angle_x, float angle_y, float angle_z)
{
	// Set rotation on the x- y- and z-axis
	rotation.x = angle_x;
	rotation.y = angle_y;
	rotation.z = angle_z;
	UpdateModel();
}

void Object::UpdateModel()
{
	// Update the model by translating, rotating and scaling
	*model = glm::translate(glm::mat4(), position);
	*model = glm::rotate(*model, glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
	*model = glm::rotate(*model, glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
	*model = glm::rotate(*model, glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));
	*model = glm::scale(*model, scale);
}


