#pragma once
#include "object.h"

class Lamppost : public Object
{
public:
	Lamppost();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};
