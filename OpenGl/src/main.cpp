#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <types.h>
#include "os/window.h"

class App : public vx::Application {
public:
    void init() override {
        glClearColor(1.0, 0.5, 0.25, 1.0);
    }
    void logic() override {}
    void draw() override {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void close() override {}
};

int main(void)
{
    vx::Window window;
    window.init();

    window.run<App>();
}