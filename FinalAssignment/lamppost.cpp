#include "lamppost.h"

Material* Lamppost::material = nullptr;
Texture* Lamppost::texture = nullptr;

Lamppost::Lamppost()
{
	mesh_type = lamppost;
	shader_type = lambert;
}

Material* Lamppost::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.1, 0.1, 0.1);
		material->diffuse_color = glm::vec3(0.3, 0.3, 0.3);
	}

	return material;
}

Texture* Lamppost::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/metal2.bmp");
		texture->active = true;
	}

	return texture;
}
