#pragma once
#include <GLFW/glfw3.h>
#include "application.h"

namespace vx {

	enum class WindowError {
		cannot_init_glfw,
		cannot_create_window,
		cannot_load_opengl
	};

	class Window {
	private:
		bool master_window;
		GLFWwindow* glfw_window;

		void internal_run(Application&);

	public:
		Window();
		~Window();

		WindowError init();
		
		template<class TimplApplication>
		void run() {
			TimplApplication app;
			internal_run(app);
		}
	};

};
