#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  // Initialize the library
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  // Create a windowed mode window and its OpenGL context
  GLFWwindow *window =
      glfwCreateWindow(640, 480, "GLFW Test Window", NULL, NULL);
  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);

  std::cout << "GLFW is working! OpenGL Version: " << glGetString(GL_VERSION)
            << std::endl;

  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // Render a simple color clear
    glClearColor(0.2f, 0.4f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
