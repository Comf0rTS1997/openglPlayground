#include <iostream>
#include <fstream>

#pragma once
class fileCtr
{
public:
	const char* fileLoc;

	fileCtr(const char* fileLocIn);
	std::string read();

private:

};

