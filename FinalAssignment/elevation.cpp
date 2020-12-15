#include "elevation.h"

Material* Elevation::material = nullptr;
Texture* Elevation::texture = nullptr;

Elevation::Elevation()
{
	mesh_type = cube;
	shader_type = lambert;
}

Material* Elevation::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.05, 0.15, 0.10);
		material->diffuse_color = glm::vec3(0.10, 0.20, 0.15);
	}

	return material;
}

Texture* Elevation::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/metal.bmp");
		texture->active = true;
	}

	return texture;
}
