#include "Core.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Math/linmath.h>
using namespace std;

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

namespace Pixelfell
{
  Application::Application(char* windowName)
  {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
      exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    window = glfwCreateWindow(mode->width, mode->height, windowName, glfwGetPrimaryMonitor(), NULL);
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);
  }

  Application::~Application()
  {

  }

  void Application::Run()
  {
    while(!glfwWindowShouldClose(window)) {
      int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        const float ratio = width / (float) height;
      glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        mat4x4 m, p, mvp;
        mat4x4_identity(m);
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mat4x4_mul(mvp, p, m);

        
    
        glfwSwapBuffers(window);
        glfwPollEvents();
    };
  }
}