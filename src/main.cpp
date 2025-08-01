#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <chrono>

static void error_callback(int error, const char* description)
{
    (void)error;
    fprintf(stderr, "Error: %s\n", description);
}

int main(void)
{
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "Green Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    auto lastTime = std::chrono::high_resolution_clock::now();
    double timeAccumulator = 0.0;
    int frameCount = 0;

    while (!glfwWindowShouldClose(window))
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        double deltaTime = std::chrono::duration<double>(currentTime - lastTime).count();
        lastTime = currentTime;

        timeAccumulator += deltaTime;
        frameCount++;

        if (timeAccumulator >= 1.0)
        {
            std::string title = "Green Window | FPS: " + std::to_string(frameCount);
            glfwSetWindowTitle(window, title.c_str());
            
            frameCount = 0;
            timeAccumulator -= 1.0;
        }

        glClearColor(0.0f, 1.0f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
