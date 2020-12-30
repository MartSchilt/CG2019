#pragma once
#include <GL/glew.h>

using namespace std;

enum MeshType { bikeFrame, bikeRack, can, cone, cube, cubeSkybox, cylinder, dog, lamppost, plane, wheel, null };

enum ShaderType { phong, lambert, standard };

struct Vao {
	GLuint id;
	int size;
};

struct Material {
	glm::vec3 ambient_color;
	glm::vec3 diffuse_color;
	glm::vec3 specular;
	float power;
};

struct Texture {
	GLuint texture_id;
	bool active;
};
