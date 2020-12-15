#include "can.h"
Material* Can::material = nullptr;
Texture* Can::texture = nullptr;

Can::Can()
{
	mesh_type = can;
	shader_type = lambert;
	grow = true;
}

Material* Can::GetMaterial()
{
	if (material == nullptr)
	{
		material = new Material();
		material->ambient_color = glm::vec3(0.9, 0.25, 0.2);
		material->diffuse_color = glm::vec3(1.0, 0.25, 0.2);
	}

	return material;
}

Texture* Can::GetTexture()
{
	if (texture == nullptr)
	{
		texture = new Texture();
		texture->texture_id = loadBMP("Textures/metal2.bmp");
		texture->active = true;
	}

	return texture;
}

void Can::Animate()
{
	if (scale.x > 6) grow = false;
	if (scale.x < 1) grow = true;
	
	if (grow) {
		scale += 0.05f;
		position.y += 0.05f;
	}
	else {
		scale -= 0.05f;
		position.y -= 0.05f;
	}
	
	rotation.z -= 1.765f;
	UpdateModel();
}
