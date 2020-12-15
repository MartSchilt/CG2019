#pragma once
#include "object.h"

class Elevation : public Object
{
public:
	Elevation();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};
