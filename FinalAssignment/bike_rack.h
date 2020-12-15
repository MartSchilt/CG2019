#pragma once
#include "object.h"

class BikeRack : public Object
{
public:
	BikeRack();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};
