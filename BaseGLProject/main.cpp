// Archivo inicial semestre 2024-1
#ifdef CMAKE_PROJECT
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#else
#include <glew.h>
#include <glfw3.h>
#include <stdio.h> // NOLINT(modernize-deprecated-headers)
#endif
// Dimensiones de la ventana
constexpr int width = 800, height = 600;

int main()
{
	// Inicializacion de GLFW
	if (!glfwInit())
	{
		printf("Fallo inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	// Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// CREAR VENTANA
	GLFWwindow *mainWindow = glfwCreateWindow(width, height, "Primer ventana", nullptr, nullptr);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	// Obtener tamano de Buffer
	int BufferWidth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	// asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	// permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Fallo inicializacion de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	// Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight);
	printf("\n 318192950 \n");
	printf("Version de Opengl: %s \n", glGetString(GL_VERSION));
	printf("Marca: %s \n", glGetString(GL_VENDOR));
	printf("Renderer: %s \n", glGetString(GL_RENDERER));
	printf("Shaders: %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	// Loop mientras no se cierra la ventana
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Recibir eventos del usuario
		glfwPollEvents();

		// Limpiar la ventana
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);

		if (glfwGetKey(mainWindow, GLFW_KEY_ESCAPE) == 1)
			break;
	}

	glfwDestroyWindow(mainWindow);
	glfwTerminate();

	return 0;
}