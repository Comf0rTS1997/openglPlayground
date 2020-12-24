#include <iostream>
#include<glew.h>
#include<glfw3.h>

#include "fileCtr.h"
#include "Shader.h"

Shader::Shader(const char* vertexIn,const char* fragIn) {
	vertexLoc = vertexIn;
	fragLoc = fragIn;
	
	fileCtr verFc(vertexLoc);
	fileCtr fragFc(fragLoc);
    std::string vertemp = "";
    std::string fragtemp = "";
    vertemp = verFc.read();
    const char* vertexSource = vertemp.c_str();
    fragtemp = fragFc.read();
    const char* fragSource = fragtemp.c_str();

    //vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "vertexShader Compile err: " << infoLog << std::endl;
    }
    else {
        std::cout << "vertexShader Compile success" << std::endl;
    }

    //fragShader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "fragmentShader Compile err: " << infoLog << std::endl;
    }
    else {
        std::cout << "fragmentShader Compile success" << std::endl;
    }

    //Combine shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ShaderProgram Link err: " << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::useThisShader() {
    glUseProgram(shaderProgram);
}