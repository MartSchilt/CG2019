#include "lamplight.h"

Material* Lamplight::material = nullptr;
Texture* Lamplight::texture = nullptr;

Lamplight::Lamplight()
{
	mesh_type = cone;
	shader_type = lambert;
}

Material* Lamplight::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.7, 0.7, 0.7);
		material->diffuse_color = glm::vec3(0.9, 0.9, 0.9);
	}

	return material;
}

Texture* Lamplight::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/metal2.bmp");
		texture->active = true;
	}

	return texture;
}
