#include <GL/glew.h>
#include "camera.h"
#include "glsl.h"
#include "object_manager.h"

//#include <list>

using namespace std;


//--------------------------------------------------------------------------------
// Consts
//--------------------------------------------------------------------------------

// Changed the window so it fits nicely on a 16:9 aspect ratio monitor
const int WIDTH = 1280, HEIGHT = 720;

// Shaders
const char* phongfragshader_name = "phongfragmentshader.fsh";
const char* lambertfragshader_name = "lambertfragmentshader.fsh";
const char* skyfragshader_name = "standardfragmentshader.fsh";
const char* vertexshader_name = "vertexshader.vsh";
const int shaderAmount = 3;

unsigned const int DELTA_TIME = 10;

//--------------------------------------------------------------------------------
// Variables
//--------------------------------------------------------------------------------

// Shader IDs
GLuint shader_id[shaderAmount];

// Uniform ID's
GLuint uniform_mv[shaderAmount];
GLuint uniform_projection[shaderAmount];
GLuint uniform_ambient[shaderAmount];
GLuint uniform_diffuse[shaderAmount];
GLuint uniform_specular[shaderAmount];
GLuint uniform_power[shaderAmount];
GLuint uniform_texture[shaderAmount];

// camera
Camera camera;

// Objectmanager for loading objects in
ObjectManager object_manager;

// Projection Matrix
glm::mat4 projection = glm::perspective(
    glm::radians(45.0f),
    1.0f * WIDTH / HEIGHT, 0.1f,
    120.0f);

// View Matrix x Model Matrix
glm::mat4 viewmodel;


//--------------------------------------------------------------------------------
// Keyboard input handling
//--------------------------------------------------------------------------------

void keyboardHandler(unsigned char key, int a, int b)
{
    if (key == 27)
        glutExit();

    // Send pressed key to the camera
    camera.ProcessInput(key, a, b);
}


//--------------------------------------------------------------------------------
// Rendering
//--------------------------------------------------------------------------------

void Render()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_MULTISAMPLE);

    for (Object* object : object_manager.GetObjects())
    {
        int shader = object->GetShaderType();

        // Attach to program_id
        glUseProgram(shader_id[shader]);

        // Set camera model and view matrix
        viewmodel = camera.GetView() * object->GetModel();

        Vao vao = object->GetVao(shader_id[shader]);
        Material* material = object->GetMaterial();
        Texture* texture = object->GetTexture();

        object->Animate();

        // Fill uniform vars
        glUniform3fv(uniform_ambient[shader], 1, glm::value_ptr(material->ambient_color));
        glUniform3fv(uniform_diffuse[shader], 1, glm::value_ptr(material->diffuse_color));
        glUniform3fv(uniform_specular[shader], 1, glm::value_ptr(material->specular));
        glUniform1f(uniform_power[shader], material->power);
        glUniform1f(uniform_texture[shader], texture->active);

        // Send mvp
        glUniformMatrix4fv(uniform_mv[shader], 1, GL_FALSE, glm::value_ptr(viewmodel));

        // load the right texture
        glBindTexture(GL_TEXTURE_2D, texture->texture_id);

        // Send vao
        glBindVertexArray(vao.id);
        glDrawArrays(GL_TRIANGLES, 0, vao.size);
        glBindVertexArray(0);
    }

    glutSwapBuffers();
}


//------------------------------------------------------------
// void Render(int n)
// Render method that is called by the timer function
//------------------------------------------------------------

void Render(int n)
{
    Render();
    glutTimerFunc(DELTA_TIME, Render, 0);
}


//------------------------------------------------------------
// void InitGlutGlew(int argc, char **argv)
// Initializes Glut and Glew
//------------------------------------------------------------

void InitGlutGlew(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutSetOption(GLUT_MULTISAMPLE, 8);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("OpenGL Assessment");
    glutDisplayFunc(Render);
    glutKeyboardFunc(keyboardHandler);
    glutTimerFunc(DELTA_TIME, Render, 0);
    glewInit();
}


//------------------------------------------------------------
// void InitShaders()
// Initializes the fragmentshader and vertexshader
//------------------------------------------------------------

void InitShaders()
{
    char* vertexshader = glsl::readFile(vertexshader_name);
    GLuint vsh_id = glsl::makeVertexShader(vertexshader);

    char* phongfragshader = glsl::readFile(phongfragshader_name);
    GLuint pfsh_id = glsl::makeFragmentShader(phongfragshader);
    shader_id[0] = glsl::makeShaderProgram(vsh_id, pfsh_id);

    char* lambertfragshader = glsl::readFile(lambertfragshader_name);
    GLuint lfsh_id = glsl::makeFragmentShader(lambertfragshader);
    shader_id[1] = glsl::makeShaderProgram(vsh_id, lfsh_id);    
    
    char* skyfragshader = glsl::readFile(skyfragshader_name);
    GLuint sbfsh_id = glsl::makeFragmentShader(skyfragshader);
    shader_id[2] = glsl::makeShaderProgram(vsh_id, sbfsh_id);
}


//------------------------------------------------------------
// void InitBuffers()
// Allocates and fills buffers
//------------------------------------------------------------

void InitBuffers()
{
    object_manager.InitWorld();

    for (int i = 0; i < shaderAmount; i++)
    {
        // Make uniform vars
        uniform_mv[i] = glGetUniformLocation(shader_id[i], "mv");
        uniform_ambient[i] = glGetUniformLocation(shader_id[i], "mat_ambient");
        uniform_diffuse[i] = glGetUniformLocation(shader_id[i], "mat_diffuse");
        uniform_specular[i] = glGetUniformLocation(shader_id[i], "mat_specular");
        uniform_power[i] = glGetUniformLocation(shader_id[i], "mat_power");
        uniform_texture[i] = glGetUniformLocation(shader_id[i], "has_texture");

        // Send mvp
        glUseProgram(shader_id[i]);
        
        // Projection matrix 
        glUniformMatrix4fv(glGetUniformLocation(shader_id[i], "projection"), 1, GL_FALSE, glm::value_ptr(projection));

        // Directional light simulating the sun.
        glUniform3fv(glGetUniformLocation(shader_id[i], "light_pos"), 1, glm::value_ptr(glm::vec3(4, 4, 4)));
    }
}


int main(int argc, char** argv)
{
    InitGlutGlew(argc, argv);
    InitShaders();
    InitBuffers();
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    // Hide console window
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);

    // Main loop
    glutMainLoop();

    return 0;
}
