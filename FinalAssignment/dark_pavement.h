#pragma once
#include "object.h"

class DarkPavement : public Object
{
public:
	DarkPavement();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};

