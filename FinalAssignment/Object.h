#pragma once
#include <vector>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"
#include "mesh_manager.h"

using namespace std;

enum ShaderType { phong, lambert, standard };

struct Material {
	glm::vec3 ambient_color;	// Ambient lighting, simulates light from other sources.
	glm::vec3 diffuse_color;	// Diffuse lighting, simulates the directional impact a light object has on an object.
	glm::vec3 specular;			// Specular lightning, simulates the bright spot of a light.
	float power;
};

struct Texture {
	GLuint texture_id;
	bool active;
};

class Object
{
public:
	Object();
	virtual ~Object();
	const virtual Vao& GetVao(GLuint shader_id) const;
	virtual Material* GetMaterial() = 0;
	virtual Texture* GetTexture() = 0;
	virtual void Animate();
	glm::mat4 GetModel();
	ShaderType GetShaderType();
	void Position(float x, float y, float z);
	void Scale(float size);
	void Scale(float scale_x, float scale_y, float scale_z);
	void Rotate(float angle_x, float angle_y, float angle_z);

protected:
	MeshType mesh_type;
	ShaderType shader_type;
	const char* texture_path;
	void UpdateModel();
	static Material* material;
	static Texture* texture;
	glm::mat4* model;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};
