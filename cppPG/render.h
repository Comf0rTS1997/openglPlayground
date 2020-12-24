#pragma once
class render
{
public:
	render(const char* verShader, const char* fragShader);
	void draw(float verData[], int verSize, int indiDatap[], int indiSize);

private:
	unsigned int VAO;
};

