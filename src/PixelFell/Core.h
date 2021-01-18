#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Pixelfell
{
  class Application
  {
    public:
      Application(char* windowName);
      virtual ~Application();
      GLFWwindow *window;

      void Run();
  };

  //to be defined in client
  Application *CreateApplication();
}