#include "fencepost.h"
Material* Fencepost::material = nullptr;
Texture* Fencepost::texture = nullptr;

Fencepost::Fencepost()
{
	mesh_type = cylinder;
	shader_type = lambert;
}

Material* Fencepost::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.35, 0.35, 0.25);
		material->diffuse_color = glm::vec3(0.40, 0.40, 0.30);
	}

	return material;
}

Texture* Fencepost::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/woodsecondary.bmp");
		texture->active = true;
	}

	return texture;
}
