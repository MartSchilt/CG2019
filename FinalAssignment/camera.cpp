#include "camera.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glsl.h"


Camera::Camera()
{
	view = new glm::mat4();
	walk_mode = true;

	// Camera location
	camera_pos = new glm::vec3(0.0f, 2.0f, 0.0f);
	camera_front = new glm::vec3(0.0f, 0.0f, 0.0f);
	camera_up = new glm::vec3(0.0f, 1.0f, 0.0f);

	// Camera direction
	yaw = 45.0f;
	pitch = 0.0f;
}

Camera::~Camera()
{
	delete camera_pos;
	delete camera_front;
	delete camera_up;
	delete view;
}

glm::mat4 Camera::GetView()
{
	*camera_front = glm::vec3(
		cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
		sin(glm::radians(pitch)),
		sin(glm::radians(yaw)) * cos(glm::radians(pitch))
	);

	*view = glm::lookAt(
		*camera_pos,
		*camera_pos + glm::normalize(*camera_front),
		*camera_up);

	return  *view;
}

void Camera::ProcessInput(unsigned char key, int a, int b)
{
	switch (key)
	{
	case'c':
		// Change the mode
		walk_mode = !walk_mode;
		*camera_pos = (walk_mode) ? glm::vec3(0.0f, 2.0f, 0.0f) : glm::vec3(0.0f, 25.0f, 40.0f);
		pitch = (walk_mode) ? 0 : -45;
		yaw = (walk_mode) ? 45 : -45;
		break;

	case'w': // Forward
		*camera_pos += (walk_mode) ?
			glm::vec3(camera_front->x, 0.0f, camera_front->z) * movement_speed :
			glm::vec3(camera_front->x, camera_front->y, camera_front->z) * movement_speed;
		break;
	case's': // Backward
		*camera_pos -= (walk_mode) ?
			glm::vec3(camera_front->x, 0.0f, camera_front->z) * movement_speed :
			glm::vec3(camera_front->x, camera_front->y, camera_front->z) * movement_speed;
		break;
	case'a': // Left
		*camera_pos += (walk_mode) ?
			glm::cross(glm::vec3(0.0, 1.0, 0.0), glm::vec3(camera_front->x, 0.0f, camera_front->z)) * movement_speed :
			glm::cross(glm::vec3(0.0, 1.0, 0.0), glm::vec3(camera_front->x, camera_front->y, camera_front->z)) * movement_speed;
		break;
	case'd': // Right
		*camera_pos += (walk_mode) ?
			glm::cross(glm::vec3(camera_front->x, 0.0f, camera_front->z), glm::vec3(0.0, 1.0, 0.0)) * movement_speed :
			glm::cross(glm::vec3(camera_front->x, camera_front->y, camera_front->z), glm::vec3(0.0, 1.0, 0.0)) * movement_speed;
		break;

	case'i': // Look up
		pitch += turning_speed;
		break;
	case'k': // Look down
		pitch -= turning_speed;
		break;
	case'q':
	case'j': // Look left
		yaw -= turning_speed;
		break;
	case'e':
	case'l': // Look right
		yaw += turning_speed;
		break;
	}
}
