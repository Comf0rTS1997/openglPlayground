#pragma once

#include<iostream>
#include<glew.h>
#include<glfw3.h>

class windowMgr
{
public:
	windowMgr(int l, int w, const char* t);
	int length;
	int width;
	const char* title;
	GLFWwindow* window;

	void run(void (*function)());
};

