#include "pavement.h"

Material* Pavement::material = nullptr;
Texture* Pavement::texture = nullptr;

Pavement::Pavement()
{
	mesh_type = plane;
	shader_type = lambert;
}

Material* Pavement::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.450, 0.250, 0.150);
		material->diffuse_color = glm::vec3(0.500, 0.300, 0.200);
	}

	return material;
}

Texture* Pavement::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/pavement.bmp");
		texture->active = true;
	}

	return texture;
}
