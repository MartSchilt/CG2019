#pragma once
#include "object.h"

class Pavement : public Object
{
public:
	Pavement();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};

