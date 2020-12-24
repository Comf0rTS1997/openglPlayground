#include<iostream>
#include<glew.h>
#include<glfw3.h>

#include "render.h"
#include "shader.h"

render::render(const char* verShader, const char* fragShader) {
    //load Shader
    Shader s(verShader, fragShader);
    s.useThisShader();
    glGenVertexArrays(1, &VAO);    
}


void draw(float verData[], int verSize, int indiDatap[], int indiSize) {
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
}