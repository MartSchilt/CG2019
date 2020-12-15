#include "other_floor.h"

Material* OtherFloor::material = nullptr;
Texture* OtherFloor::texture = nullptr;

OtherFloor::OtherFloor()
{
	mesh_type = cube;
	shader_type = lambert;
}

Material* OtherFloor::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.355, 0.355, 0.269);
		material->diffuse_color = glm::vec3(0.400, 0.400, 0.300);
	}

	return material;
}

Texture* OtherFloor::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/brick.bmp");
		texture->active = true;
	}

	return texture;
}
