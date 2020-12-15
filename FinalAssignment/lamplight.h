#pragma once
#include "object.h"

class Lamplight : public Object
{
public:
	Lamplight();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};
