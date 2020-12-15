#include "ground_floor.h"

Material* GroundFloor::material = nullptr;
Texture* GroundFloor::texture = nullptr;

GroundFloor::GroundFloor()
{
	mesh_type = cube;
	shader_type = lambert;
}

Material* GroundFloor::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.300, 0.150, 0.100);
		material->diffuse_color = glm::vec3(0.450, 0.300, 0.200);
	}

	return material;
}

Texture* GroundFloor::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/wall.bmp");
		texture->active = true;
	}

	return texture;
}
