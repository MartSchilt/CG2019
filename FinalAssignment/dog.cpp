#include "dog.h"

Material* Dog::material = nullptr;
Texture* Dog::texture = nullptr;

Dog::Dog()
{
	mesh_type = dog;
	shader_type = lambert;
}

Material* Dog::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.10, 0.40, 0.25);
		material->diffuse_color = glm::vec3(0.10, 0.40, 0.25);
	}

	return material;
}

Texture* Dog::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/metal2.bmp");
		texture->active = true;
	}

	return texture;
}
