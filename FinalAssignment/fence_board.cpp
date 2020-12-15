#include "fence_board.h"
Material* FenceBoard::material = nullptr;
Texture* FenceBoard::texture = nullptr;

FenceBoard::FenceBoard()
{
	mesh_type = cube;
	shader_type = lambert;
}

Material* FenceBoard::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.35, 0.35, 0.25);
		material->diffuse_color = glm::vec3(0.40, 0.40, 0.30);
	}

	return material;
}

Texture* FenceBoard::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/wood.bmp");
		texture->active = true;
	}

	return texture;
}
