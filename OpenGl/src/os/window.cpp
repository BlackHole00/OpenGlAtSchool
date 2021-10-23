#pragma once
#include <glad/glad.h>
#include "window.h"


static bool glfw_initialized = false;
static bool opengl_loaded = false;
static bool init_glfw() {
	if (!glfw_initialized) {
		if (!glfwInit()) {
			return false;
		}

		glfw_initialized = true;
	}

	return true;
}
static void deinit_glfw() {
	if (glfw_initialized) {
		glfwTerminate();

		glfw_initialized = false;
	}
}
static int load_opengl() {
	if (!opengl_loaded) {
		return gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		opengl_loaded = true;
	}

	return 1;
}

namespace vx {

	Window::Window() {
		init_glfw();

		master_window = true;
		glfw_window = nullptr;
	}

	Window::~Window() {
		deinit_glfw();
	}

	WindowError Window::init() {
		glfw_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!glfw_window)
		{
			return WindowError::cannot_create_window;
		}

		glfwMakeContextCurrent(glfw_window);

		if (!load_opengl()) {
			return WindowError::cannot_load_opengl;
		}
	}

	void Window::internal_run(Application& app) {
		app.init();

		while (!glfwWindowShouldClose(glfw_window)) {
			app.logic();
			app.draw();

			glfwSwapBuffers(glfw_window);
			glfwPollEvents();
		}

		app.close();

		if (master_window) {
			deinit_glfw();
		}
	}
	
};