#pragma once
#include <GL/glew.h>

using namespace std;

enum MeshType { bikeFrame, bikeRack, can, cone, cube, cubeSkybox, cylinder, lamppost, plane, wheel, null };

enum ShaderType { phong, lambert, standard };

struct Vao {
	GLuint id;
	int size;
};

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
