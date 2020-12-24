#include "fileCtr.h"

fileCtr::fileCtr(const char* fileLocIn) {
	fileCtr::fileLoc = fileLocIn;
}

std::string fileCtr::read() {
	std::ifstream fileStream(fileLoc);
	std::string result((std::istreambuf_iterator<char>(fileStream)),
		std::istreambuf_iterator<char>());
	return result;
}