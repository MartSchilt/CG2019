#pragma once
#include "object.h"

class Roof : public Object
{
public:
	Roof();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};
