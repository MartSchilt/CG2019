#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "structs_and_enums.h"

using namespace std;

class MeshManager
{
public:
	static MeshManager* GetInstance();
	Vao GetVao(GLuint shader_id, MeshType type);
	Vao LoadVao(GLuint shader_id, const char* path);
	GLuint BuildVao(GLuint shader_id, vector<glm::vec3> vertices, vector<glm::vec3> normals, vector<glm::vec2> uvs);

private:
    MeshManager();
	static MeshManager* instance;
	Vao vaos[null] = {0};

    // The plane is an primitive mesh thus we define the vertices, normals and uvs here
    vector<glm::vec3> plane_vertices{
        glm::vec3(1.0, 0, 1.0),
        glm::vec3(-1.0, 0, -1.0),
        glm::vec3(-1.0, 0, 1.0),
        glm::vec3(1.0, 0, 1.0),
        glm::vec3(1.0, 0, -1.0),
        glm::vec3(-1.0, 0, -1.0)
    };

    vector<glm::vec3> plane_normals{
        glm::vec3(0.0, 1.0, 0.0),
        glm::vec3(0.0, 1.0, 0.0),
        glm::vec3(0.0, 1.0, 0.0),
        glm::vec3(0.0, 1.0, 0.0),
        glm::vec3(0.0, 1.0, 0.0),
        glm::vec3(0.0, 1.0, 0.0)
    };

    vector<glm::vec2> plane_uvs{
        glm::vec2(1.0, -0.0),
        glm::vec2(0.0, -1.0),
        glm::vec2(0.0, -0.0),
        glm::vec2(1.0, -0.0),
        glm::vec2(1.0, -1.0),
        glm::vec2(0.0, -1.0)
    };
};

