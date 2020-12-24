#pragma once
class Shader
{
public:
	unsigned int shaderProgram;
	Shader(const char* vertexIn, const char* fragIn);
	void useThisShader();


private:
	const char* vertexLoc;
	const char* fragLoc;
	
};

