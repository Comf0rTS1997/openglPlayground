#include<iostream>
#include<glew.h>
#include<glfw3.h>

#include "shader.h"

int main() {
    GLFWwindow* window;

    

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(720, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //init GLEW
    if (glewInit() != GLEW_OK) {
        return -1;
    }

    //load Shader
    Shader s("vertex.shader", "frag.shader");
    s.useThisShader();


    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    

    //Put data into buffer
    float position[] = {
       -0.2f, 0.0f, 0.0f, //0
       0.2f, 0.0f, 0.0f, //1
       -0.2f, 0.4f, 0.0f, //2
       0.2f, 0.4f, 0.0f, //3

       0.3f, 0.0f, 0.0f, //4
       0.7f, 0.0f, 0.0f, //5
       0.3f, 0.4f, 0.0f, //6
       0.7f, 0.4f, 0.0f //7
    };
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(position), position, GL_STREAM_DRAW);
    // Tell opengl how to use the data in the buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    int indicies[] = {
        0, 1, 2,
        1, 3, 2,
        4, 5, 6,
        5, 7, 6
    };
    unsigned int iBuffer;
    glGenBuffers(1, &iBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STREAM_DRAW);

    float a = 0.0005f;
    float v = 0.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 12,GL_UNSIGNED_INT, 0);

        v -= a;
        if (position[1] <= -1.0f) {
            v = 0 - v - 0.005f;
            if (v <= 0.00001f) {
                v = 0.0f;
                a = 0.0f;
            }
        }

        position[1] += v;
        position[4] += v;
        position[7] += v;
        position[10] += v;


        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(position), position);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);

        // change color
        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        int vertexColorLocation = glGetUniformLocation(s.shaderProgram, "u_Color");
        glUniform4f(vertexColorLocation, 1.0f - greenValue, greenValue, 1.0f, 1.0f);
        s.useThisShader();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}