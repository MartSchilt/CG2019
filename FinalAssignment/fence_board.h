#pragma once
#include "object.h"

class FenceBoard : public Object
{
public:
	FenceBoard();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();

private:
	static Material* material;
	static Texture* texture;
};
