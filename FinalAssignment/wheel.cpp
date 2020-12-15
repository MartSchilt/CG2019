#include "wheel.h"
Material* Wheel::material = nullptr;
Texture* Wheel::texture = nullptr;

Wheel::Wheel()
{
	mesh_type = wheel;
	shader_type = lambert;
}

Material* Wheel::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.1, 0.1, 0.1);
		material->diffuse_color = glm::vec3(0.3, 0.3, 0.3);
	}

	return material;
}

Texture* Wheel::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/metal2.bmp");
		texture->active = true;
	}

	return texture;
}

void Wheel::Animate()
{
	if (position.z < 0)
		position.z = 40;

	position.z -= 0.1;
	rotation.x -= 10;
	UpdateModel();
}
