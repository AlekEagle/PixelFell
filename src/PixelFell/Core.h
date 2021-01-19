#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <queue>

namespace Pixelfell
{
  class Input
  {
    public:
      typedef void (*InputHandlerFunction)(Application, int, int, int);
  };

  class Application
  {
    public:
      Application(char* windowName);
      virtual ~Application();
      GLFWwindow *window;
      void Run();
    private:
      std::queue<Input::InputHandlerFunction> *InputEventLoop = new std::queue<Input::InputHandlerFunction>({NULL});
  };

  //to be defined in client
  Application *CreateApplication();
}