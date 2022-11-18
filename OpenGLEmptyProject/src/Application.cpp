#include "glad/gl.h"
#include "GLFW/glfw3.h"

#include <iostream>

int main() {
	if (glfwInit() == GLFW_FALSE)
	{
		std::cout << "GLFW Initialization Failed!" << std::endl;
		system("pause");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 450, "Hello OpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);
	
	const int GLAD_VERSION = gladLoadGL(glfwGetProcAddress);
	if (GLAD_VERSION == 0)
	{
		std::cout << "GLAD Initialization Failed!" << std::endl;
		system("pause");
		return 2;
	}


	while (!glfwWindowShouldClose(window))
	{
		static const float ClearColor[4] = { 0.2f, 0.3f, 0.8f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, ClearColor);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}