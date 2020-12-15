#include "bike_frame.h"
Material* BikeFrame::material = nullptr;
Texture* BikeFrame::texture = nullptr;

BikeFrame::BikeFrame()
{
	mesh_type = bikeFrame;
	shader_type = lambert;
}

Material* BikeFrame::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.1, 0.1, 0.1);
		material->diffuse_color = glm::vec3(0.3, 0.3, 0.3);
	}

	return material;
}

Texture* BikeFrame::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/metal2.bmp");
		texture->active = true;
	}

	return texture;
}

void BikeFrame::Animate()
{
	if (position.z < 0)
		position.z = 40;

	position.z -= 0.1;
	UpdateModel();
}
