#include "roof.h"

Material* Roof::material = nullptr;
Texture* Roof::texture = nullptr;

Roof::Roof()
{
	mesh_type = plane;
	shader_type = lambert;
}

Material* Roof::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.05, 0.10, 0.05);
		material->diffuse_color = glm::vec3(0.10, 0.15, 0.10);
	}

	return material;
}

Texture* Roof::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/roof.bmp");
		texture->active = true;
	}

	return texture;
}
