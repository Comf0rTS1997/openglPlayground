#include "windowMgr.h"

windowMgr::windowMgr(int l, int w, const char* t) {
	length = l;
	width = w;
	title = t;


    /* Initialize the library */
    if (!glfwInit())
        throw 0;  // cannot init glfw


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(length, width, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw 1; // cannot create window
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //init GLEW
    if (glewInit() != GLEW_OK) {
        throw 2; // cannot init glew
    }


}

void windowMgr::run(void (*loopFunction)()) {
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        (*loopFunction)();
        

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}