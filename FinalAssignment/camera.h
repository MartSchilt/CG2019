#pragma once
#include <glm/glm.hpp>

class Camera
{
public:
	Camera();
	~Camera();
	glm::mat4 GetView();
	void ProcessInput(unsigned char key, int a, int b);

private:
	glm::mat4* view;
	bool walk_mode;

	glm::vec3* camera_pos;
	glm::vec3* camera_front;
	glm::vec3* camera_up;

	float pitch;
	float yaw;

	float movement_speed = 0.5f;
	float turning_speed = 2.0f;
};

