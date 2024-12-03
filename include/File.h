#pragma once

#include<cstddef>
#include<string>
#include "./AbstractFile.h"

class File : public AbstractFile{
	public:
		File(std::string name, std::string path) : AbstractFile(name, path) {};
		size_t getSize(); 
	private:
		std::string content;
};
