#pragma once
#include "object.h"

class chickenleg : public object
{
public:
	chickenleg();
	const virtual vao& get_vao(GLuint shader_id) const;
	virtual material* get_material();
	virtual texture* get_texture();
private:
	static vao* _vao;
	static material* _material;
	static texture* _texture;
};
