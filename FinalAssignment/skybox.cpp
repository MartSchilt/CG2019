#include "skybox.h"

Material* Skybox::material = nullptr;
Texture* Skybox::texture = nullptr;


Skybox::Skybox()
{
	mesh_type = cubeSkybox;
	shader_type = standard;
	texture_path = "Textures/skybox.bmp";
}

Material* Skybox::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.2, 0.2, 0.2);
		material->diffuse_color = glm::vec3(1, 1, 1);
	}

	return material;
}

Texture* Skybox::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP(texture_path);
		texture->active = true;
	}

	return texture;
}
