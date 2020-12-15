#include "mesh_manager.h"
#include "objloader.h"

MeshManager* MeshManager::instance = nullptr;

MeshManager::MeshManager()
{}

MeshManager* MeshManager::GetInstance()
{
    if (instance == nullptr)
        instance = new MeshManager();
    return instance;
}

Vao MeshManager::GetVao(GLuint shader_id, MeshType type)
{
    if (vaos[type].id == 0)
    {
        Vao temp;

        switch (type)
        {
        case bikeFrame:
            vaos[type] = LoadVao(shader_id, "Objects/bikeframe.obj");
            break;
        case bikeRack:
            vaos[type] = LoadVao(shader_id, "Objects/bikerack.obj");
            break;
        case can:
            vaos[type] = LoadVao(shader_id, "Objects/can.obj");
            break;
        case cone:
            vaos[type] = LoadVao(shader_id, "Objects/cone.obj");
            break;
        case cube:
            vaos[type] = LoadVao(shader_id, "Objects/cube.obj");
            break;
        case cubeSkybox:
            vaos[type] = LoadVao(shader_id, "Objects/cube_inverted.obj");
            break;
        case cylinder:
            vaos[type] = LoadVao(shader_id, "Objects/cylinder.obj");
            break;
        case lamppost:
            vaos[type] = LoadVao(shader_id, "Objects/lamppost.obj");
            break;
        case plane: 
            temp.id = BuildVao(shader_id, plane_vertices, plane_normals, plane_uvs);
            temp.size = plane_vertices.size();
            vaos[type] = temp;
            break;
        case wheel:
            vaos[type] = LoadVao(shader_id, "Objects/wheel.obj");
            break;
        default:
            break;
        }
    }

    return vaos[type];
}

Vao MeshManager::LoadVao(GLuint shader_id, const char* path)
{
    vector<glm::vec3> vertices;
    vector<glm::vec3> normals;
    vector<glm::vec2> uvs;

    loadOBJ(path, vertices, uvs, normals);
    
    Vao temp;
    temp.id = BuildVao(shader_id, vertices, normals, uvs);
    temp.size = vertices.size();

    return temp;
}

GLuint MeshManager::BuildVao(GLuint shader_id, vector<glm::vec3> vertices, vector<glm::vec3> normals, vector<glm::vec2> uvs)
{

    // Attribute id's
    GLuint position_id = glGetAttribLocation(shader_id, "position");
    GLuint normal_id = glGetAttribLocation(shader_id, "normal");
    GLuint uv_id = glGetAttribLocation(shader_id, "uv");

    // vbo's
    GLuint vbo_vertices;
    GLuint vbo_normals;
    GLuint vbo_uvs;

    GLuint vao;

    // vbo for vertices
    glGenBuffers(1, &vbo_vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
    glBufferData(GL_ARRAY_BUFFER,
        vertices.size() * sizeof(glm::vec3),
        &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for normals
    glGenBuffers(1, &vbo_normals);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
    glBufferData(GL_ARRAY_BUFFER,
        normals.size() * sizeof(glm::vec3),
        &normals[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for uvs
    glGenBuffers(1, &vbo_uvs);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
    glBufferData(GL_ARRAY_BUFFER,
        uvs.size() * sizeof(glm::vec2),
        &uvs[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Allocate memory for vao
    glGenVertexArrays(1, &vao);

    // Bind to vao
    glBindVertexArray(vao);

    // Bind vertices to vao
    glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
    glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(position_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Bind normals to vao
    glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
    glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(normal_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Bind uvs to vao
    glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
    glVertexAttribPointer(uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(uv_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Stop bind to vao
    glBindVertexArray(0);

    return vao;
}
