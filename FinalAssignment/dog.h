#pragma once
#include "object.h"

class Dog : public Object
{
public:
	Dog();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};

