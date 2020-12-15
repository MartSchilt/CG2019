#pragma once
#include "object.h"

class OtherFloor : public Object
{
public:
	OtherFloor();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};
