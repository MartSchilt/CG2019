#include "dirt.h"

Material* Dirt::material = nullptr;
Texture* Dirt::texture = nullptr;

Dirt::Dirt()
{
	mesh_type = plane;
	shader_type = lambert;
}

Material* Dirt::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.250, 0.150, 0.100);
		material->diffuse_color = glm::vec3(0.400, 0.300, 0.150);
	}

	return material;
}

Texture* Dirt::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/dirt.bmp");
		texture->active = true;
	}

	return texture;
}
