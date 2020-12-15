#pragma once
#include "object.h"

class Skybox : public Object
{
public:
	Skybox();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();
private:
	static Material* material;
	static Texture* texture;
	bool direction;
};