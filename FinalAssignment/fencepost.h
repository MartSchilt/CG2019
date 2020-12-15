#pragma once
#include "object.h"

class Fencepost : public Object
{
public:
	Fencepost();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};
