#pragma once
#include "object.h"

class GroundFloor : public Object
{
public:
	GroundFloor();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};

