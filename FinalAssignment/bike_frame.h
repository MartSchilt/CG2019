#pragma once
#include "object.h"

class BikeFrame : public Object
{
public:
	BikeFrame();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();
	virtual void Animate();

private:
	static Material* material;
	static Texture* texture;
};
