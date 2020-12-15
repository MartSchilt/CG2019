#pragma once
#include "object.h"

class Can : public Object
{
public:
	Can();
	virtual Material* GetMaterial();
	virtual Texture* GetTexture();
	virtual void Animate();

private:
	static Material* material;
	static Texture* texture;
	bool grow;
};
