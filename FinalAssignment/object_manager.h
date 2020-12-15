#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"
#include "objloader.h"
#include "texture.h"
#include "object.h"

#include "camera.h"
#include <list>
#include "object_manager.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	std::vector<Object*> GetObjects();
	void InitWorld();
private:
	std::vector<Object*>* CreateBike(float x, float z);
	std::vector<Object*>* CreateBikeRacks(float x, float z);
	std::vector<Object*>* CreateFence(float xMin, float xMax, float zMin, float zMax);
	std::vector<Object*>* CreateFloor();
	std::vector<Object*>* CreateHouse(float x, float z);
	std::vector<Object*>* CreateLamp(float x, float z);
	std::vector<Object*>* CreateOther();
	std::vector<Object*> objects;

	// 0 = red pavement
	// 1 = dark pavement
	// 2 = dirt
	const int floor[20][17] = {
		{0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 2, 2, 2, 2, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 2, 2, 2, 2, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
	};
};

