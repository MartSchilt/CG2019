#pragma once
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"
#include "structs_and_enums.h";
#include "mesh_manager.h"

using namespace std;

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
