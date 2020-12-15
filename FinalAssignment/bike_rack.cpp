#include "bike_rack.h"

Material* BikeRack::material = nullptr;
Texture* BikeRack::texture = nullptr;

BikeRack::BikeRack()
{
	mesh_type = bikeRack;
	shader_type = lambert;
}

Material* BikeRack::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.5, 0.5, 0.5);
		material->diffuse_color = glm::vec3(0.6, 0.6, 0.6);
	}

	return material;
}

Texture* BikeRack::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/metal2.bmp");
		texture->active = true;
	}

	return texture;
}
