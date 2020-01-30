#include <glad/glad.h>
#include <glfw3.h>
#include <cstdlib>
#include <iostream>
#include "shader/ShaderBuilder.h"
#include "shader/ShaderProgramBuilder.h"

#define STB_IMAGE_IMPLEMENTATION

#include "texture/TextureFactory.h"
#include "shape/ShapeFactory.h"

/**
 * Basic Width of the window
 */
const int WIDTH = 800;

/**
 * Basic Height of the window
 */
const int HEIGHT = 600;

/**
 * Fragment Shader Source Path used in the Program.
 */
const char *fragmentShaderSourcePath = "../resources/fragments/Thales3DCube_Fragment_Shader.fs";

/**
 * Vertex Shader Source Path used in the Program.
 */
const char *vertexShaderSourcePath = "../resources/vertex/Thales3DCube_VertexTriangle_Shader.vs";

Shape *shape;
Texture *texture;
ShaderProgram *program;

/**
 * Generate a random float number between 0 and 1. It allows
 * the user to generate random color.
 * @return the random float number generated.
 */
static float getRandomNumber() {
    return glm::mod(((double) rand() / (RAND_MAX) + 1), 1.0);
}

/**
 * Function which allow the user to change the background, move the shape in the plan and modify the
 * shape when the right key is pressed.
 */
static void escape_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        shape = ShapeFactory::getInstance().get();
    else if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
        float red = getRandomNumber();
        float green = getRandomNumber();
        float blue = getRandomNumber();
        glClearColor(red, blue, green, 1.0f);
    } else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        program->updateTranslateTool(glm::vec3(-0.1f, 0.0f, 0.0f));
    else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        program->updateTranslateTool(glm::vec3(0.1f, 0.0f, 0.0f));
    else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        program->updateTranslateTool(glm::vec3(0.0f, 0.0f, -0.1f));
    else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        program->updateTranslateTool(glm::vec3(0.0f, 0.0f, 0.1f));
}

/**
 * Change the texture displayed if the user makes a left click on the window.
 */
static void mouseCallBack(GLFWwindow *window, int key, int scancode, int action) {
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {
        texture = TextureFactory::getInstance().get();
    }
}

static void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window;
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    window = glfwCreateWindow(WIDTH, HEIGHT, "Thales_Cube - by Maxime Cots", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, escape_callback);
    glfwSetMouseButtonCallback(window, mouseCallBack);

    TextureFactory::init();
    ShapeFactory::init();

    texture = TextureFactory::getInstance().get();
    shape = ShapeFactory::getInstance().get();

    ShaderBuilder shaderBuilder;
    Shader fragmentShader = shaderBuilder.build(fragmentShaderSourcePath);
    Shader vertexShader = shaderBuilder.build(vertexShaderSourcePath);
    std::vector<Shader *> shadersVector = {&fragmentShader, &vertexShader};
    ShaderProgramBuilder programBuilder;
    program = programBuilder.setShaders(shadersVector)->build();
    program->setProjectionMatrix(WIDTH, HEIGHT);
    for (Shader * shaderPtr : shadersVector){
        glDeleteShader(shaderPtr->getId());
    }
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);
        texture->apply();
        program->animate();
        shape->draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteProgram(program->getId());
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
