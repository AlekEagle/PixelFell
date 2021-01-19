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
    glfwWindowHint(GLFW_RESIZABLE, 0);

    window = glfwCreateWindow(1920, 1080, windowName, NULL, NULL);
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
      glViewport(0, 0, width, height);
      glClear(GL_COLOR_BUFFER_BIT);

      //Game Loop logic Start
      
      //Game Loop logic Stop

      glfwSwapBuffers(window);
      glfwPollEvents();
    };
  }
}