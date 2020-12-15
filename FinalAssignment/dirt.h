#pragma once
#include "object.h"

class Dirt : public Object
{
public:
	Dirt();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};

