#include "dark_pavement.h"

Material* DarkPavement::material = nullptr;
Texture* DarkPavement::texture = nullptr;

DarkPavement::DarkPavement()
{
	mesh_type = plane;
	shader_type = lambert;
}

Material* DarkPavement::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.2, 0.2, 0.2);
		material->diffuse_color = glm::vec3(0.4, 0.4, 0.4);
	}

	return material;
}

Texture* DarkPavement::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/darkpavement.bmp");
		texture->active = true;
	}

	return texture;
}
