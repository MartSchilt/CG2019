#pragma once
#include "object.h"

class Wheel : public Object
{
public:
	Wheel();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();
	virtual void Animate();

private:
	static Material* material;
	static Texture* texture;
};
